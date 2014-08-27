#include <stdio.h>
#include <limits.h>

long amount[101][101];

long max(long x, long y){ return (x < y)? y : x; }

int main()
{
  int i,j,x,y,t,n;
  long c;
  scanf("%d",&n);
  for(i=0;i<n;++i){
    for(j=0;j<n;++j){
      scanf("%d",&t);
      amount[i+1][j+1] = amount[i+1][j] + amount[i][j+1] - amount[i][j] + t;
    }
  }
  c = LONG_MIN;
  for(i=1;i<=n;++i)
    for(j=1;j<=n;++j)
      for(y=1;y<=i;++y)
        for(x=1;x<=j;++x)
          c = max(c, amount[i][j]-amount[y-1][j]-amount[i][x-1]+amount[y-1][x-1]);
  printf("%ld\n", c);
  return 0;
}
