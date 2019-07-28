#include <bits/stdc++.h>
using namespace std;

int main(void){
  int n, aux, res, cien = 0, cincuenta = 0, veinte = 0, diez = 0, cinco = 0, dos = 0, uno = 0;
  cin >> n;
  aux = n;
  if ((res = aux / 100.00) >= 1) {
    aux -= 100.00*res;
    cien += res;
  } if ((res = aux / 50.00) >= 1) {
    aux -= 50.00*res;
    cincuenta += res;
  } if ((res = aux / 20.00) >= 1) {
    aux -= 20.00*res;
    veinte += res;
  } if ((res = aux / 10.00) >= 1) {
    aux -= 10.00*res;
    diez += res;
  } if ((res = aux / 5.00) >= 1) {
    aux -= 5.00*res;
    cinco += res;
  } if ((res = aux / 2.00) >= 1) {
    aux -= 2.00*res;
    dos += res;
  } if ((res = aux / 1.00) >= 1) {
    aux -= 1.00*res;
    uno += res;
  }
  cout << n << endl;
  cout << cien << " nota(s) de R$ 100,00" << endl;
  cout << cincuenta << " nota(s) de R$ 50,00" << endl;
  cout << veinte << " nota(s) de R$ 20,00" << endl;
  cout << diez << " nota(s) de R$ 10,00" << endl;
  cout << cinco << " nota(s) de R$ 5,00" << endl;
  cout << dos << " nota(s) de R$ 2,00" << endl;
  cout << uno << " nota(s) de R$ 1,00" << endl;
  return 0;
}
