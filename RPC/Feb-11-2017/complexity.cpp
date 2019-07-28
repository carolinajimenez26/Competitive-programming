#include <bits/stdc++.h>
using namespace std;


int main(void){

  unordered_map<char,int> mapa;
  vector<int> v;
  string cadena;
  int n = 0, tmp = 1, borrador = 0; // numero de letras diferentes que hay que borrar
  cin>>cadena;

  for(int i = 0; i< cadena.length(); i++){ // ej mapa['a'] = 3
    if (!mapa.count(cadena[i])) { // si no existe
      mapa[cadena[i]] = 1;
      n++;
    } else { // si existe
      mapa[cadena[i]] += 1;
    }
  }
  // calcula el resto
  if (n == 1 || n == 2) n = 0;
  if (n > 2) {
    n -= 2;
  }

  for (auto i : mapa) {
    v.push_back(i.second);
  }

  sort(v.begin(),v.end());

  for (int i = 0; i < n; i++) {
    borrador += v[i];
  }

  cout << borrador << endl;

  return 0;
}
