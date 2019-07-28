#include <bits/stdc++.h>
using namespace std;

int main(void){
  int C;
  float N, sum = 0;
  char T;
  cin >> C >> T;
  for(int i = 0; i < 12; i++){
    for(int j = 0; j < 12; j++){
      cin >> N;
      if(i == C) sum += N;
    }
  }
  if (T == 'S') cout << fixed << setprecision(1) << sum << endl;
  else cout << fixed << setprecision(1) << sum / 12.0 << endl;
  return 0;
}
