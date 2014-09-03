#include <iostream>
#include <iomanip>
using namespace std;

int arr[10];

void nprt(int n)
{
  cout << setw(5) << n;
}

int main()
{
  int i,j,n,e,amount;
  for (;;) {
    cin >> n; cin.ignore();
    if (!n) break;
    for (i=0; i<n; ++i) arr[i] = 0;
    for (i=0; i<n; ++i) {
      amount = 0;
      for (j=0; j<n; ++j) {
        cin >> e;
        nprt(e);
        amount += e;
        arr[j] += e;
      }
      nprt(amount);
      cout << endl;
    }
    amount = 0;
    for (i=0; i<n; ++i) {
      nprt(arr[i]);
      amount += arr[i];
    }
    nprt(amount);
    cout << endl;
  }
  return 0;
}
