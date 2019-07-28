#include <bits/stdc++.h>
using namespace std;

int main(void){
  int pass;
  cin >> pass;
  while(pass != 2002){
    cout << "Senha Invalida" << endl;
    cin >> pass;
  }
  cout << "Acesso Permitido" << endl;
  return 0;
}
