#include <bits/stdc++.h>
using namespace std;

int main(void){
  int DDD;
  cin >> DDD;
  unordered_map<int, string> D;
  D[61] = "Brasilia";
  D[71] = "Salvador";
  D[11] = "Sao Paulo";
  D[21] = "Rio de Janeiro";
  D[32] = "Juiz de Fora";
  D[19] = "Campinas";
  D[27] = "Vitoria";
  D[31] = "Belo Horizonte";
  if (!D.count(DDD)) cout << "DDD nao cadastrado" << endl;
  else cout << D[DDD] << endl;
  return 0;
}
