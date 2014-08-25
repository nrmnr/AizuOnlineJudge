#include <stdio.h>
#include <math.h>

int n,cloth[10][10];

void drop(int x, int y, int delta)
{
  if(0<=x && x<10 && 0<=y && y<10) cloth[y][x] += delta;
}

void drop_ink(int x, int y, int size, int delta)
{
  switch(size){
  case 3:
    drop(x, y-2, delta);
    drop(x+2, y, delta);
    drop(x, y+2, delta);
    drop(x-2, y, delta);
    // trough
  case 2:
    drop(x+1, y-1, delta);
    drop(x+1, y+1, delta);
    drop(x-1, y+1, delta);
    drop(x-1, y-1, delta);
    // through
  case 1:
    drop(x, y-1, delta);
    drop(x+1, y, delta);
    drop(x, y+1, delta);
    drop(x-1, y, delta);
    drop(x, y, delta);
  }
}

int judge()
{
  int i,j;
  for(i=0; i<10; ++i)
    for(j=0; j<10; ++j)
      if(cloth[i][j] < 0)
        return -1;
  for(i=0; i<10; ++i)
    for(j=0; j<10; ++j)
      if(cloth[i][j] > 0)
        return 1;
  return 0;
}

int solve(int remain_drop, int amount)
{
  int jd = judge();
  if(jd < 0) return 0;
  if(remain_drop == 0) return (jd == 0);
  if(0 < amount && amount < 4) return 0;

  int x,y,size,low,up,discount;
  for(size=1; size<=3; ++size){
    if(size == 3 && amount < 13) continue;
    if(size == 2 && amount < 9) continue;
    switch(size){
    case 3: low = 2; up = 8; discount = 13; break;
    case 2: low = 1; up = 9; discount = 9; break;
    case 1: low = 1; up = 9; discount = 4; break;
    }
    for(y=low; y<up; ++y){
      for(x=low; x<up; ++x){
        drop_ink(x, y, size, -1);
        if(solve(remain_drop-1, amount-discount)){
          printf("%d %d %d\n", x, y, size);
          return 1;
        } else {
          drop_ink(x, y, size, 1);
        }
      }
    }
  }
  return 0;
}

int main()
{
  int i,j,amount=0;
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
