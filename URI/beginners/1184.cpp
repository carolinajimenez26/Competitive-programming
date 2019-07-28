#include <bits/stdc++.h>
using namespace std;

int main(void){
  float N, sum = 0, cont = 0;
  char T;
  cin >> T;
  for(int i = 0; i < 12; i++){
    for(int j = 0; j < 12; j++){
      cin >> N;
      if(j < i){
        sum += N;
        cont++;
      }
    }
  }
  if (T == 'S') cout << fixed << setprecision(1) << sum << endl;
  else cout << fixed << setprecision(1) << sum / cont << endl;
  return 0;
}
