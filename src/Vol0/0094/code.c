#include <stdio.h>
#define UNIT 3.3057850
int main()
{
  int a,b;
  scanf("%d%d",&a,&b);
  printf("%lf\n",a*b/UNIT);
  return 0;
}
