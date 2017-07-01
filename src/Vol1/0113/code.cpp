#include <iostream>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
  int p, q;
  for (;cin >> p >> q;) {
    map<int, int> digit;
    for (int c = 0; ; ++c) {
      int d = p / q;
      if (c > 0) cout << d;
      if (p % q == 0) break;
      p -= d * q;
      p *= 10;
      if (digit.find(p) != digit.end()) {
        cout << endl;
        for (int i = 0; i < digit[p]; ++i) cout << " ";
        for (int i = digit[p]; i < c; ++i) cout << "^";
        break;
      }
      digit[p] = c;
    }
    cout << endl;
  }

  return 0;
}
