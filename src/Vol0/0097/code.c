#include <stdio.h>

int flags[101];

int min(int x, int y){ return (x < y)? x : y; }
void prt()
{
  int i;
  for(i=0;i<100;++i){
    if(flags[i]) fprintf(stderr, "+%d", i);
  }
  fprintf(stderr, "\n");
}

int solve(int n, int s, int count, int upper)
{
  if(n==1){
    if(flags[s] == 0){
      flags[s] = 1;
      prt();
      flags[s] = 0;
      return count+1;
    } else {
      return count;
    }
  }
  int i;
  for(i=min(s,upper);i>s/2;--i){
    flags[i] = 1;
    count = solve(n-1, s-i, count, i-1);
    flags[i] = 0;
  }
  return count;
}

int main()
{
  int i,n,s,c;
  for(;scanf("%d%d",&n,&s) && (n||s);){
    fprintf(stderr, "%d %d\n", n, s);
    if(s > 864){
      puts("0");
      continue;
    }
    for(i=0;i<=100;++i) flags[i] = 0;
    printf("%d\n", solve(n, s, 0, 100));
  }
  return 0;
}
