#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// #define DEBUG

const int MAX_GRAM = 5000/100;
const int CEIL = 10000;

vector<int> price_memo(MAX_GRAM+1, CEIL);

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
#ifdef DEBUG
  for (int i = 0; i <= MAX_GRAM; ++i) {
    if (price_memo[i] < CEIL)
      cerr << setw(5) << price_memo[i];
    else
      cerr << setw(5) << "----";
  }
  cerr << endl;
#endif
}

void init()
{
  price_memo[0] = 0;
  for (int i = 0; i < unit_count; ++i) {
    Unit u = units[i];
    for (int j = 0; j+u.gram <= MAX_GRAM; j++) {
      price_memo[j+u.gram] = min(price_memo[j+u.gram], price_memo[j]+u.price);
    }
    prt();
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
