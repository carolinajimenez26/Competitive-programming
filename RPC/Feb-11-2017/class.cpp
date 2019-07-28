#include <bits/stdc++.h>
using namespace std;

vector<string> split(string &s) {
  stringstream ss;
  ss << s;
  vector<string> v;
  string tok;
  while (ss >> tok) {
    v.push_back(tok);
  }
  return v;
}

int tonum(string &s) {
  stringstream ss;
  ss << s;
  int out;
  ss >> out;
  return out;
}

int main(void){

  map<string,int> mapa;
  vector<string> v;
  string nombre, apellido_nombre; // v tiene nombre y apellido
  string n;
  int n2;
  getline(cin,n);
  n2 = tonum(n);

  for(int i = 0; i < n2; i++){
    getline(cin,nombre);
    v = split(nombre);
    apellido_nombre = v[1]+" "+v[0];
    mapa[apellido_nombre] = 1;
  }

  for(std::map<string,int>::iterator it = mapa.begin(); it != mapa.end(); ++it){
    nombre = it->first;
    v = split(nombre);
    cout << v[1] << " " << v[0] << endl;
  }

  return 0;
}
