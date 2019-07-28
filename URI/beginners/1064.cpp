#include <bits/stdc++.h>
using namespace std;

int main(void){
  int cant = 0;
  float n, sum = 0;
  for(int i = 0; i < 6; i++){
    cin >> n;
    if (n > 0) {
      cant++;
      sum += n;
    }
  }
  cout << cant << " valores positivos" << endl;
  cout << fixed << setprecision(1) << sum / cant << endl;
  return 0;
}
