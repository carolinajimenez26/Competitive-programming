#include <bits/stdc++.h>
using namespace std;

int main(void){
  int N = 0, alcool = 0, gasolina = 0, diesel = 0;
  while(N != 4){
    cin >> N;
    if (N == 1) alcool++;
    if (N == 2) gasolina++;
    if (N == 3) diesel++;
  }
  cout << "MUITO OBRIGADO" << endl;
  cout << "Alcool: " << alcool << endl;
  cout << "Gasolina: " << gasolina << endl;
  cout << "Diesel: " << diesel << endl;
  return 0;
}
