#include <iostream>
#include <algorithm>
using namespace std;

static const int NMAX = 1000;
static const int WMAX = 10000;
int n, arr[NMAX], arr_s[NMAX], wmin;
int ind[WMAX+1];

int solve()
{
  bool flag[NMAX];
  for (int i = 0; i < n; ++i) {
    arr_s[i] = arr[i];
    flag[i] = false;
  }
  sort(arr_s, arr_s + n);
  for (int i = 0; i < n; ++i) ind[arr_s[i]] = i;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (flag[i]) continue;
    int sum = 0;
    int cycle_wmin = WMAX;
    int cycle_n = 0;
    for (int cur = i; !flag[cur];) {
      flag[cur] = true;
      cycle_n++;
      int w = arr[cur];
      cycle_wmin = min(cycle_wmin, w);
      sum += w;
      cur = ind[w];
    }
    ans += min(
               sum + (cycle_n - 2) * cycle_wmin,
               sum + (cycle_n + 1) * wmin + cycle_wmin
               );
  }
  return ans;
}

int main(int argc, char *argv[])
{
  cin >> n;
  wmin = WMAX;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    wmin = min(wmin, arr[i]);
  }
  cout << solve() << endl;
  return 0;
}
