#include <bits/stdc++.h>
using namespace std;
vector<long long> F( 61, -1.0 );

void fib(){
  F[0] = 0;
  F[1] = 1;
  for(int i = 2; i <= 60; i++){
    if (F[i] == -1) {
      F[i] = F[i-1] + F[i-2];
    }
  }
}

int main(void){
  fib();
  int cases, N;
  cin >> cases;
  while (cases--) {
    cin >> N;
    cout << "Fib(" << (int)N << ") = " << F[(int)N] << endl;
  }
  return 0;
}
