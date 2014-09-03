#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef vector<int> Nums;

Nums freq(const Nums& a)
{
  map<int, int> count;
  for (Nums::const_iterator it = a.begin(); it != a.end(); ++it) {
    count[*it] += 1;
  }
  Nums ret;
  for (Nums::const_iterator it = a.begin(); it != a.end(); ++it) {
    ret.push_back(count[*it]);
  }
  return ret;
}

int main()
{
  int n,t;
  for (;;) {
    cin >> n;
    if (!n) break;
    Nums a,b;
    for (;n-->0;) {
      cin >> t;
      a.push_back(t);
    }
    int c;
    for (c = 0; ; ++c, a = b) {
      b = freq(a);
      if (a == b) break;
    }
    cout << c << endl;
    for (Nums::iterator it = a.begin(); it != a.end(); ++it) {
      if (it != a.begin()) cout << " ";
      cout << *it;
    }
    cout << endl;
  }
  return 0;
}
