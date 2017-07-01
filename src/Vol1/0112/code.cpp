#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  for (int n; cin >> n && n;) {
    int ts[n];
    for (int i = 0; i < n; ++i) {
      cin >> ts[i];
    }
    sort(ts, ts + n);

    unsigned long long int total = 0, sub = 0;
    for (int i = 0; i < n-1; ++i) {
      sub += ts[i];
      total += sub;
    }

    cout << total << endl;
  }
  return 0;
}
