#include <stdio.h>

long long memo[10][1001];

void prt(int b, int e)
{
  int i,j;
  for(j=b; j<e; ++j){
    fprintf(stderr, " %3d:", j);
    for(i=0; i<10; ++i){
      fprintf(stderr, " %3lld", memo[i][j]);
    }
    fprintf(stderr, "\n");
  }
  fprintf(stderr, "--------------------------------\n");
}

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
  /* prt(0,20); */
  /* prt(480,501); */
  /* prt(860,880); */
  for(;scanf("%d%d",&n,&s) && (n||s);){
    printf("%lld\n", memo[n][s]);
  }
  return 0;
}
