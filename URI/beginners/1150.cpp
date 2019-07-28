#include <bits/stdc++.h>
using namespace std;

int main(void){
  int X, Z, aux, cont = 1;
  cin >> X;
  aux = X - 1;
  while(aux <= X){
    cin >> Z;
    aux = Z;
  }
  aux = X + 1;
  while(X < Z){
    X += aux;
    cont++;
    aux++;
  }
  cout << cont << endl;
  return 0;
}
