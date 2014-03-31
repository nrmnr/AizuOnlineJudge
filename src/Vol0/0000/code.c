#include <stdio.h>
int main(int argc, char *argv[])
{
  int a=0, b;
  for (b=0; a<10; (b = ++b % 10)? printf("%dx%d=%d\n",a,b,a*b) : a++);
  return 0;
}
