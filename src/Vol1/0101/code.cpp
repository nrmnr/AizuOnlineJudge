#include <iostream>
#include <string>
using namespace std;

string repl(string s)
{
  string f("Hoshino"), t("Hoshina");
  for (string::size_type p = s.find(f); p != string::npos; p = s.find(f, p + t.length())) {
    s.replace(p, f.length(), t);
  }
  return s;
}

int main()
{
  int n;
  string s;
  cin >> n;
  cin.ignore();
  for (; n-->0;) {
    getline(cin, s);
    cout << repl(s) << endl;
  }
  return 0;
}
