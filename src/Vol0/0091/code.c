#include <stdio.h>
#include <math.h>

struct {
  int dx;
  int dy;
} drop_pts[] = {
  {0,0}, {0,-1}, {1,0}, {0,1}, {-1,0},
  {1,-1}, {1,1}, {-1,1}, {-1,-1},
  {0,-2}, {2,0}, {0,2}, {-2,0}
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

int solve(int remain_drop, int blur_amount)
{
  if(remain_drop == 0) return (blur_amount == 0);
  if(blur_amount < remain_drop * blur_count[1]) return 0;
  if(blur_amount > remain_drop * blur_count[3]) return 0;

  int x,y,size;
  for(y=1; y<9; ++y){
    for(x=1; x<9; ++x){
      if(cloth[y][x] <= 0) continue;
      for(size=3; size>=1; --size){
        if(blur_amount < blur_count[size]) continue;
        if(!enable_drop(x, y, size)) continue;
        drop_ink(x, y, size, -1);
        if(cloth[y][x] < cloth[y-1][x] || (y >= 2 && cloth[y-1][x] < cloth[y-2][x])){
          drop_ink(x, y, size, 1); // recover
          return 0;
        }
        if(!solve(remain_drop-1, blur_amount-blur_count[size])){
          drop_ink(x, y, size, 1); // recover
        } else {
          printf("%d %d %d\n", x, y, size);
          return 1;
        }
      }
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
