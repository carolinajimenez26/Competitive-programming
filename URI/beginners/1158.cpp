#include <bits/stdc++.h>
using namespace std;

int main(void){
  int N, X, Y, sum = 0, cont = 0;
  cin >> N;
  while(N--){
    cin >> X >> Y;
    while(cont < Y){
      if(X % 2 != 0) {
        sum += X;
        cont++;
      }
      X++;
    }
    cout << sum << endl;
    cont = 0;
    sum = 0;
  }
  return 0;
}
