#include <bits/stdc++.h>
using namespace std;

int main(void){
  float v, d, a;
  while (cin >> v >> d) {
    a = 3.14*((d*d)/4.0);
    cout << fixed << setprecision(2) << "ALTURA = " << v/a << endl;
    cout << fixed << setprecision(2) << "AREA = " << a << endl;
  }
  return 0;
}
