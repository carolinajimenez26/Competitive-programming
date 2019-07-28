#include <bits/stdc++.h>
using namespace std;

int main(void){
  int A, B;
  cin >> A >> B;
  if (B > A) cout << "O JOGO DUROU " << B - A << " HORA(S)" << endl;
  else if (A >= B) cout << "O JOGO DUROU " << (24 - A) + B << " HORA(S)" << endl;
  return 0;
}
