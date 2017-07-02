#include <iostream>
using namespace std;

int n, q;
int A[20];
bool solve(int i, int m)
{
  if (m == 0) return true;
  if (i >= n) return false;
  return solve(i+1, m) || solve(i+1, m - A[i]);
}

int main(int argc, char *argv[])
{
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> A[i];
  cin >> q;
  for (; q-->0;) {
    int m;
    cin >> m;
    cout << (solve(0, m) ? "yes" : "no") << endl;
  }
  return 0;
}
