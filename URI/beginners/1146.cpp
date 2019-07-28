#include <bits/stdc++.h>
using namespace std;

int main(void){
  int X = 1;
  while(true){
    cin >> X;
    if (X == 0) break;
    for(int i = 1; i <= X; i++){
      if (i == X) cout << i;
      else cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}
