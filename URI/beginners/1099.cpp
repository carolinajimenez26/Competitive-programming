#include <bits/stdc++.h>
using namespace std;

int main(void){
  int N, X, Y, tmp, sum = 0;
  cin >> N;
  while(N--){
    cin >> X >> Y;
    if (X > Y) {
      tmp = X;
      X = Y;
      Y = tmp;
    }
    for(int i = X + 1; i < Y; i++){
      if (i % 2 != 0) sum += i;
    }
    cout << sum << endl;
    sum = 0;
  }
  return 0;
}
