#include <stdio.h>
int table[500000];
void init()
{
  for (int i=3; i<1000; i+=2)
    if (!table[(i-3)/2])
      for (int j = i*3; j<1000000; table[(j-3)/2]=1, j+=i*2);
}

int count_prime(int n)
{
  if (n < 2) return 0;
  int c, i;
  for (c=1,i=3; i<=n; i+=2)
    c += !table[(i-3)/2];
  return c;
}

int main()
{
  init();
  for (int n; ~scanf("%d",&n); printf("%d\n",count_prime(n)));
  return 0;
}
