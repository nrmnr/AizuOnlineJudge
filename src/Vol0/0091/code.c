#include <stdio.h>
#include <math.h>

int n,cloth[10][10];

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
  printf("%d\n", amount);
  return 0;
}
