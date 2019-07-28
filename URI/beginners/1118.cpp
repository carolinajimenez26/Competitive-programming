#include <bits/stdc++.h>
using namespace std;

int main(void){
  double N, sum = 0, X = 1;
  int aux = 0;
  bool flag = false;
  while (true) {
    if (X == 1.0) flag = true;
    else flag = false;
    if (X == 2.0) break;
    while (aux != 2 && flag) {
      cin >> N;
      if (N >= 0 && N <= 10) {
        sum += N;
        aux++;
      } else cout << "nota invalida" << endl;
    }
    if (aux == 2) {
      cout << "media = " << fixed << setprecision(2) << sum / 2.0 << endl;
      aux = 0;
      sum = 0;
    }
    cout << "novo calculo (1-sim 2-nao)" << endl;
    cin >> X;
  }
  return 0;
}
