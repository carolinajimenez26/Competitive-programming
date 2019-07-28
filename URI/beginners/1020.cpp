#include <bits/stdc++.h>
using namespace std;

int main(void){
  int X, ano, mes;
  cin >> X;
  ano = X/(365.0);
  X -= ano*365.0;
  mes = X/30.0;
  X -= mes*30.0;
  cout << ano << " ano(s)" << endl;
  cout << mes << " mes(es)" << endl;
  cout << X << " dia(s)" << endl;
  return 0;
}
