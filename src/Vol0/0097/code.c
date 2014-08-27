#include <stdio.h>

int up_bounds[] = {-1,100,199,297,394,490,585,679,772,864};

int solve(int n, int s, int count, int low_bound)
{
  if(n == 0) return (s == 0)? count+1 : count;
  if(s > up_bounds[n]) return count;
  int i;
  for(i=low_bound;i<=100 && i<=s;++i){
    count = solve(n-1, s-i, count, i+1);
  }
  return count;
}

int main()
{
  int i,n,s,c;
  for(;scanf("%d%d",&n,&s) && (n||s);){
    printf("%d\n", solve(n, s, 0, 0));
  }
  return 0;
}
