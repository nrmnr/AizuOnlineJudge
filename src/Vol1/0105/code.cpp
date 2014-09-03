#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
  string word;
  int page;
  set<string> words;
  map<string, vector<int> > pages;
  for (;;) {
    cin >> word >> page; cin.ignore();
    if (cin.eof()) break;
    words.insert(word);
    pages[word].push_back(page);
  }
  vector<string> wv(words.begin(), words.end());
  for (vector<string>::iterator w = wv.begin(); w != wv.end(); ++w) {
    word = *w;
    cout << word << endl;
    vector<int> pg(pages[word].begin(), pages[word].end());
    sort(pg.begin(), pg.end());
    for (vector<int>::iterator p = pg.begin(); p != pg.end(); ++p) {
      if (p != pg.begin()) cout << " ";
      cout << *p;
    }
    cout << endl;
  }
  return 0;
}
