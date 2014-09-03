#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

vector<int> price_memo(51, 1<<15);

struct Unit {
  int gram;
  int price;
} units[] = {
  {2, 380},
  {3, 550},
  {5, 850},
  {2*5, 380*5*80/100},
  {3*4, 550*4*85/100},
  {5*3, 850*3*88/100}
};
const int unit_count = sizeof(units) / sizeof(units[0]);

void prt()
{
  for (int i=0; i<23; ++i) {
    if (price_memo[i] >= 1<<15)
      cerr << setw(5) << "----";
    else
      cerr << setw(5) << price_memo[i];
  }
  cerr << endl;
}

void init()
{
  price_memo[0] = 0;
  for (int i = 0; i < unit_count; ++i) {
    Unit u = units[i];
    for (int j = 0; j+u.gram <= 50; j++) {
      price_memo[j+u.gram] = min(price_memo[j+u.gram], price_memo[j]+u.price);
    }
    // prt();
  }
}

int main()
{
  init();
  int wants;
  for (;;) {
    cin >> wants;
    if (!wants) break;
    cout << price_memo[wants/100] << endl;
  }
  return 0;
}
