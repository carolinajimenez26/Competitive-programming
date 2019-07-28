#include <bits/stdc++.h>
using namespace std;

int main(void){
  int C;
  string g;
  cin >> C;
  while (C--) {
    cin >> g;
    cout << fixed << setprecision(2) << g.size() / 100.00 << endl;
  }
  return 0;
}
