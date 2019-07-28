#include <bits/stdc++.h>
using namespace std;

int main(void){
  double N, sum = 0;
  int aux = 0;
  while (aux != 2) {
    cin >> N;
    if (N >= 0 && N <= 10) {
      sum += N;
      aux++;
    } else cout << "nota invalida" << endl;
  }
  cout << "media = " << fixed << setprecision(2) << sum / 2.0 << endl;
  return 0;
}
