#include <bits/stdc++.h>
using namespace std;

int main(void){
  int X, horas, minutos;
  cin >> X;
  horas = X*(1/60.0)*(1/60.0);
  X -= horas*60*60;
  minutos = X/60;
  X -= minutos*60;
  cout << horas << ":" << minutos << ":" << X << endl;
  return 0;
}
