#include <stdio.h>

int height[99], n;

int comp(int *a, int *b)
{
  return *a - *b;
}

int main()
{
  for (; ~scanf("%d", height+n); ++n);
  qsort(height, n, sizeof(int), comp);
  for (; n-->7; printf("%d\n", height[n]));
  return 0;
}
