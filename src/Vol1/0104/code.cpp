#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

void seek(const vector<string>& field)
{
  set<pair<int,int> > footprint;
  int x=0, y=0;
  for (;;) {
    pair<int,int> fp(x,y);
    if (footprint.find(fp) != footprint.end()) {
      cout << "LOOP" << endl;
      return;
    }
    footprint.insert(fp);
    char c = field[y][x];
    switch (c) {
    case '<': x--; break;
    case '>': x++; break;
    case '^': y--; break;
    case 'v': y++; break;
    default: // '.'
      cout << x << " " << y << endl;
      return;
    }
  }
}

int main()
{
  string s;
  int h, w;
  for (;;) {
    cin >> h >> w; cin.ignore();
    if (!h && !w) break;
    vector<string> field;
    for (;h-->0;) {
      cin >> s;
      field.push_back(s);
    }
    seek(field);
  }
  return 0;
}
