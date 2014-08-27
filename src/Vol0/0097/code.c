#include <stdio.h>

long long memo[10][1001];

int main()
{
  int i,n,s;
  memo[0][0] = 1;
  for(i=0; i<=100; ++i){
    for(n=8; n>=0; --n){
      for(s=0; s+i<=1000; ++s){
        memo[n+1][s+i] += memo[n][s];
      }
    }
  }
  for(;scanf("%d%d",&n,&s) && (n||s);){
    printf("%lld\n", memo[n][s]);
  }
  return 0;
}
