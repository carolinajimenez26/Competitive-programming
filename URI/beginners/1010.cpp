#include <bits/stdc++.h>
using namespace std;

int main(void){
  int product, amount;
  float price, total = 0;
  for(int i = 0; i <= 1; i++){
    cin >> product >> amount >> price;
    total += amount * price;
  }
  cout << "VALOR A PAGAR: R$ " << fixed << setprecision(2) << total << endl;
  return 0;
}
