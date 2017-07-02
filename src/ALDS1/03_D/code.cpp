#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[])
{
  stack<int> s1;
  stack<pair<int, int> > s2;
  int total = 0;
  char c;
  for (int i = 0; cin >> c; ++i) {
    if (c == '\\') {
      s1.push(i);
    } else if (c == '/' && !s1.empty()) {
      int b = s1.top();
      s1.pop();
      int area = i - b;
      total += area;
      while (!s2.empty() && b < s2.top().first) {
        area += s2.top().second;
        s2.pop();
      }
      s2.push(make_pair(b, area));
    }
  }

  cout << total << endl;

  vector<int> ans;
  for (; !s2.empty(); s2.pop()) {
    ans.push_back(s2.top().second);
  }
  reverse(ans.begin(), ans.end());
  cout << ans.size();
  for (vector<int>::iterator it = ans.begin(); it != ans.end(); ++it) {
    cout << " " << *it;
  }
  cout << endl;
  return 0;
}
