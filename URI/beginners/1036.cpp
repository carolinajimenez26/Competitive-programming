#include <bits/stdc++.h>
using namespace std;

int main(void){
  float A, B, C, det;
  cin >> A >> B >> C;
  det = B * B - (4 * A * C);
  if (A == 0 || det < 0) cout << "Impossivel calcular" << endl;
  else {
    cout << "R1 = " << fixed << setprecision(5) << ( -B + sqrt(det) ) / (2 * A) << endl;
    cout << "R2 = " << fixed << setprecision(5) << ( -B - sqrt(det) ) / (2 * A) << endl;
  }
  return 0;
}
