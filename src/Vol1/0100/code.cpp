#include <iostream>
#include <vector>
using namespace std;

const int THRESHOULD = 1000000;
const int EMP_MAX = 4000;
long sales[EMP_MAX+1];

int main()
{
  int i,n;
  for (;;) {
    cin >> n;
    if (!n) break;
    for (i=EMP_MAX+1; i-->0;) sales[i] = 0;
    vector<int> que;
    int id, price, count;
    for (; n-->0;) {
      cin >> id >> price >> count;
      if (sales[id] == 0) {
        que.push_back(id);
      }
      sales[id] += static_cast<long>(price) * count;
    }
    bool exist = false;
    for (vector<int>::iterator it = que.begin(); it != que.end(); ++it) {
      id = *it;
      if (sales[id] >= THRESHOULD) {
        cout << id << endl;
        exist = true;
      }
    }
    if (!exist) cout << "NA" << endl;
  }
  return 0;
}
