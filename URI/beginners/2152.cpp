#include <bits/stdc++.h>
using namespace std;

int main(void){
  int cases, h, m, op;
  cin >> cases;
  while (cases--) {
    cin >> h >> m >> op;
    if (h / 10 == 0) cout << "0" << h << ":";
    else cout << h << ":";
    if (m / 10 == 0) cout << "0" << m << " - ";
    else cout << m << " - ";
    if (op == 0) cout << "A porta fechou!" << endl;
    else cout << "A porta abriu!" << endl;
  }
  return 0;
}
