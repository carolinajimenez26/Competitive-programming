#include <bits/stdc++.h>
using namespace std;

int main(void){
  double N[12][12], sum = 0, cont = 0;
  int k = 7;
  char T;
  cin >> T;
  for(int i = 0; i < 12; i++){
    for(int j = 0; j < 12; j++){
      cin >> N[i][j];
    }
  }

  for(int i = 5; i > 0; i--){
    for(int j = k; j < 12; j++){
      sum += N[i][j];
      cont += 1.0;
    }
    k++;
  }
  k = 7;
  for(int i = 6; i <= 10; i++){
    for(int j = k; j < 12; j++){
      sum += N[i][j];
      cont += 1.0;
    }
    k++;
  }

  if (T == 'S') cout << fixed << setprecision(1) << sum << endl;
  else cout << fixed << setprecision(1) << sum / cont << endl;
  return 0;
}
