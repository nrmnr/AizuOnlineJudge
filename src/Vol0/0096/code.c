#include <stdio.h>

int memo[5][4001];

int solve(int n, int rn)
{
  if(memo[rn][n] != -1) return memo[rn][n];

  int i,s,ts;
  i = (n < 1000)? n : 1000;
  ts = 0;
  for(;i>=0;--i){
    s = solve(n-i, rn-1);
    if(s == -2) break;
    if(s > 0) ts += s;
  }
  return memo[rn][n] = ts;
}

int main()
{
  int i,j,n,def;
  for(i=1; i<=4; ++i){
    def = (i==1)? 1 : -1;
    for(j=0; j<=4000; ++j){
      memo[i][j] = (j<=i*1000)? def : -2;
    }
  }
  for(;~scanf("%d",&n);){
    printf("%d\n",solve(n, 4));
  }
  return 0;
}
