#include <bits/stdc++.h>
using namespace std;

int main(void){
  float A;
  cin >> A;
  if (A < 0 || A > 100) cout << "Fora de intervalo" << endl;
  if (A >= 0 && A <= 25) cout << "Intervalo [0,25]" << endl;
  if (A > 25 && A <= 50) cout << "Intervalo (25,50]" << endl;
  if (A > 50 && A <= 75) cout << "Intervalo (50,75]" << endl;
  if (A > 75 && A <= 100) cout << "Intervalo (75,100]" << endl;
  return 0;
}
