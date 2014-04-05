#include <stdio.h>
char s[99], *p=s+30;
int main()
{
  for (; ~(*p=getchar()); --p);
  puts(p+2);
  return 0;
}
