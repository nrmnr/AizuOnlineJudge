#include <stdio.h>
int main()
{
  int n, m = 1e5;
  for(scanf("%d",&n); n--; m*=1e3)
    m = m*1.05e-3 + .99;
  printf("%d\n", m);
  return 0;
}
