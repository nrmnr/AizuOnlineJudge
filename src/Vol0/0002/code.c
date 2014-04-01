#include <stdio.h>

int a, b;
int main()
{
  for (; ~scanf("%d %d",&a,&b); printf("%d\n",b))
    for (a+=b,b=0;a;a/=10,b++);
  return 0;
}
