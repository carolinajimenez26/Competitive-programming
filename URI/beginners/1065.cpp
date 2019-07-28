#include <bits/stdc++.h>
using namespace std;

int main(void){
  int cant = 0, n;
  for(int i = 0; i < 5; i++){
    cin >> n;
    if (n % 2 == 0) {
      cant++;
    }
  }
  cout << cant << " valores pares" << endl;
  return 0;
}
