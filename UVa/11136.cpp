#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

struct compare {
  bool operator() (const int& lhs, const int& rhs) const
  { return lhs > rhs; }
};

int main(void) {
  int n, x, y;
  long long count;
  multiset<int, compare> ms;
  multiset<int>::iterator it, rit;
  while (cin >> n) {
    if (n == 0) break;
    ms.clear();
    count = 0;
    for (int i = 0; i < n; i++) { // days
      cin >> x; // number of bills
      for (int j = 0; j < x; j++) { // bills
        cin >> y;
        ms.insert(y);
      }
      it = ms.begin();
      rit = ms.end();
      --rit;
      count += (*it - *rit);
      ms.erase(it);
      ms.erase(rit);
    }
    cout << count << endl;
  }
  return 0;
}
