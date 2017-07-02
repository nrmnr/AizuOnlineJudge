#include <iostream>
using namespace std;

const int MAX = 100000;
int n, k;
int w[MAX];

int count(int p)
{
  int i = 0;
  for (int j = 0; j < k; ++j) {
    int s = 0;
    for (; s + w[i] <= p; ++i) {
      s += w[i];
      if (i == n - 1) return n;
    }
  }
  return i;
}

int main(int argc, char *argv[])
{
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }

  int l = 0, r = MAX * 10000, m;
  while (r - l > 1) {
    m = (l + r) / 2;
    int c = count(m);
    (c >= n)? r = m : l = m;
  }
  cout << r << endl;
  return 0;
}
