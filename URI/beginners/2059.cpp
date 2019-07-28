#include <bits/stdc++.h>
using namespace std;

int main(void){
  bool p, r, a;
  int j1, j2;
  cin >> p >> j1 >> j2 >> r >> a;
  if (r && a) //si j1 engaña y j2 lo acusa
    cout << "Jogador 2 ganha!" << endl;
  else if (r && !a) //si j1 engaña y j2 no lo acusa
    cout << "Jogador 1 ganha!" << endl;
  else if (!r && a) //si j1 no engaña pero j2 acusa
    cout << "Jogador 1 ganha!" << endl;
  else { //si j1 no engaña y j2 no acusa (!r && !a)
    if ((j1 + j2) % 2 == 0 && p) //si la suma es par y j1 escogió par
      cout << "Jogador 1 ganha!" << endl;
    else if ((j1 + j2) % 2 != 0 && !p) //si la suma es impar y j1 escogió impar
      cout << "Jogador 1 ganha!" << endl;
    else //solo dicen estos casos
      cout << "Jogador 2 ganha!" << endl;
  }
  return 0;
}
