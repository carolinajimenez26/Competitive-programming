#include <bits/stdc++.h>
using namespace std;

int main(void){
  int X, Y, aux = 1;
  cin >> X >> Y;
  for(int i = 1; i <= Y/X; i++){
    for(int j = 0; j < X; j++){
      if (j == X - 1) cout << aux ;
      else cout << aux << " ";
      aux++;
    }
    cout << endl;
  }
  return 0;
}
