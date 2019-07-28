#include <bits/stdc++.h>
using namespace std;

int main(void){
  int cases;
  float A, B, C;
  cin >> cases;
  while (cases--) {
    cin >> A >> B >> C;
    cout << fixed << setprecision(1) << (A * 2 + B * 3 + C * 5) / 10 << endl;
  }
  return 0;
}
