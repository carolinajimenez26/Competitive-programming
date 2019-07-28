#include <bits/stdc++.h>
using namespace std;

int main(void){
  double N;
  cin >> N;
  cout << "N[0] = " << fixed << setprecision(4) << N << endl;
  for(int i = 1; i < 100; i++){
    cout << "N[" << i << "] = " << fixed << setprecision(4) << N / 2.0 << endl;
    N /= 2;
  }
  return 0;
}
