#include <bits/stdc++.h>
using namespace std;

int main(void){
  int cases, i = 1, j = 1, aux = 0;
  cin >> cases;
  while(cases--){
    for(int k = 0; k <= 1; k++){
      if (k == 1) cout << i << " " << j << " " << (i * j) - aux << endl;
      else cout << i << " " << j << " " << (i * j) << endl;
      j++;
    }
    i++;
    j = i*i;
    aux++;
  }
  return 0;
}
