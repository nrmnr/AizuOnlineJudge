#include <iostream>
#include <string>
using namespace std;

int main()
{
  int n,out=0,pt=0,run=0;
  string s;
  cin >> n; cin.ignore();
  for (;n>0;) {
    cin >> s;
    if (s == "OUT") {
      out++;
      if (out == 3) {
        cout << pt << endl;
        out = pt = run = 0;
        n--;
      }
    } else if (s == "HIT") {
      run++;
      if (run == 4) {
        pt++;
        run = 3;
      }
    } else if (s == "HOMERUN") {
      pt += run + 1;
      run = 0;
    }
  }
  return 0;
}
