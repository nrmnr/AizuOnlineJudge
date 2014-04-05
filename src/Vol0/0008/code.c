#include <stdio.h>
int main()
{
  int n, count, comb, digit, amount;
  for (; ~scanf("%d",&n); printf("%d\n",count)) {
    for (count = comb = 0; comb < 1e4; ++comb) {
      for (digit = comb, amount = 0; digit > 0; digit /= 10)
        amount += digit % 10;
      if (amount == n) count++;
    }
  }
  return 0;
}
