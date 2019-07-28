#include <bits/stdc++.h>
using namespace std;

int main(void){
  int op = 1, i = 0, g = 0, empates = 0, juegos = 0, i_aux = 0, g_aux = 0;
  while (op != 2) {
    cin >> i >> g;
    if (i > g) i_aux++;
    if (g > i) g_aux++;
    if (i == g) empates++;
    juegos++;
    cout << "Novo grenal (1-sim 2-nao)" << endl;
    cin >> op;
  }
  cout << juegos << " grenais" << endl;
  cout << "Inter:" << i_aux << endl;
  cout << "Gremio:" << g_aux << endl;
  cout << "Empates:" << empates << endl;
  if (i_aux > g_aux) cout << "Inter venceu mais" << endl;
  if (g_aux > i_aux) cout << "Gremio venceu mais" << endl;
  if (i_aux == g_aux) cout << "Não houve vencedor" << endl;
  return 0;
}
