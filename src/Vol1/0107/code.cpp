#include <iostream>
#include <cmath>
using namespace std;

int l[3],r,n;

void init()
{
  int t;
  if (l[0] > l[1]) { t = l[0]; l[0] = l[1]; l[1] = t; }
  if (l[1] > l[2]) { t = l[1]; l[1] = l[2]; l[2] = t; }
}

bool accept(int a, int b, int r)
{
  double ah = a/2.0;
  double bh = b/2.0;
  return sqrt(ah*ah + bh*bh) < r;
}

int main()
{
  for (;;) {
    cin >> l[0] >> l[1] >> l[2];
    if (l[0]+l[1]+l[2] == 0) break;
    init();
    cin >> n;
    for (;n-->0;) {
      cin >> r;
      cout << (accept(l[0], l[1], r)? "OK" : "NA") << endl;
    }
  }
  return 0;
}
