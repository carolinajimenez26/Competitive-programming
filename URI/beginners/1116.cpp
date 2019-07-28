#include <bits/stdc++.h>
using namespace std;

int main(void){
  int N;
  float X, Y;
  cin >> N;
  while(N--){
    cin >> X >> Y;
    if (Y != 0) cout << fixed << setprecision(1) << X / Y << endl;
    else cout << "divisao impossivel" << endl;
  }
  return 0;
}
