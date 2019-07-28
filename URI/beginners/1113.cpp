#include <bits/stdc++.h>
using namespace std;

int main(void){
  int x, y;
  while(true) {
    cin >> x >> y;
    if (x == y) break;
    if (x > y) cout << "Decrescente" << endl;
    else cout << "Crescente" << endl;
  }
}
