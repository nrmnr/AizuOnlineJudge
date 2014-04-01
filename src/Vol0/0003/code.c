#include <stdio.h>
int a,b,c;
int main()
{
  for (scanf("%d",&a); ~scanf("%d%d%d",&a,&b,&c); printf(a+b-c&&b+c-a&&c+a-b?"NO\n":"YES\n"))
    a*=a,b*=b,c*=c;
  return 0;
}
