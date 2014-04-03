#include <stdio.h>
int a,b,x,y,t;
int main()
{
  for (; ~scanf("%d%d",&a,&b); printf("%d %d\n", x, a/x*b))
    for (x=a<b?b:a,y=a+b-x; y; t=x,x=y,y=t) x %= y;
  return 0;
}
