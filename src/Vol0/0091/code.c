#include <stdio.h>
#include <math.h>

typedef struct {
  int dx;
  int dy;
} Point;
Point drop_pts[] = {
  {0,0}, {0,-1}, {1,0}, {0,1}, {-1,0},
  {1,-1}, {1,1}, {-1,1}, {-1,-1},
  {0,-2}, {2,0}, {0,2}, {-2,0}
};
Point drop_target[] = {
  {0, 0}, // dummy
  {0, 1}, {1, 1}, {0, 2}
};

int blur_count[] = {
  0, // dummy
  5, 9, 13
};

int cloth[10][10];

void drop(int x, int y, int delta)
{
  if(0<=x && x<10 && 0<=y && y<10) cloth[y][x] += delta;
}

void drop_ink(int x, int y, int size, int delta)
{
  int i;
  for(i=0; i<blur_count[size]; ++i){
    drop(x+drop_pts[i].dx, y+drop_pts[i].dy, delta);
  }
}

int enable_drop(int x, int y, int size)
{
  int i;
  for(i=0; i<blur_count[size]; ++i){
    if(x+drop_pts[i].dx < 0 || 10 <= x+drop_pts[i].dx ||
       y+drop_pts[i].dy < 0 || 10 <= y+drop_pts[i].dy) return 0;
    if(cloth[y+drop_pts[i].dy][x+drop_pts[i].dx] <= 0) return 0;
  }
  return 1;
}

int find_first_blur(int *px, int *py)
{
  int x, y;
  for(y=0; y<10; ++y)
    for(x=0; x<10; ++x)
      if(cloth[y][x] > 0){
        *px = x;
        *py = y;
        return 1;
      }
  return 0;
}

int solve(int remain_drop, int blur_amount)
{
  if(remain_drop == 0) return (blur_amount == 0);
  if(blur_amount < remain_drop * blur_count[1]) return 0;
  if(blur_amount > remain_drop * blur_count[3]) return 0;

  int x,y,fx,fy,size;
  if(!find_first_blur(&fx,&fy)) return 0;

  for(size=3; size>=1; --size){
    if(blur_amount < blur_count[size]) continue;
    x = fx + drop_target[size].dx;
    y = fy + drop_target[size].dy;
    if(!enable_drop(x, y, size)) continue;
    drop_ink(x, y, size, -1);
    if(!solve(remain_drop-1, blur_amount-blur_count[size])){
      drop_ink(x, y, size, 1); // recover
    } else {
      printf("%d %d %d\n", x, y, size);
      return 1;
    }
  }

  return 0;
}

int main()
{
  int n,i,j,amount=0;
  scanf("%d",&n);
  for(i=0; i<10; ++i){
    for(j=0; j<10; ++j){
      scanf("%d", &cloth[i][j]);
      amount += cloth[i][j];
    }
  }
  solve(n, amount);
  return 0;
}
