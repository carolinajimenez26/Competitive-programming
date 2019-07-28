#include <bits/stdc++.h>
using namespace std;

int main(void){
  double N[12][12], sum = 0, cont = 0;
  int k = 1;
  char T;
  cin >> T;
  for(int i = 0; i < 12; i++){
    for(int j = 0; j < 12; j++){
      cin >> N[i][j];
    }
  }

  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 12; j++){
      if (j >= k && j < 12 - k){
        sum += N[i][j];
        cont += 1.0;
      }
    }
    k++;
  }

  if (T == 'S') cout << fixed << setprecision(1) << sum << endl;
  else cout << fixed << setprecision(1) << sum / cont << endl;
  return 0;
}
