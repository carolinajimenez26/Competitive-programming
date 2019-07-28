#include <bits/stdc++.h>
using namespace std;

int main(void){
  int N;
  cin >> N;
  int fib[N];
  fib[0] = 0; fib[1] = 1;
  for(int i = 2; i < N; i++) fib[i] = fib[i-1] + fib[i-2];
  for(int i = 0; i < N; i++){
    if (i == N - 1) cout << fib[i] << endl;
    else cout << fib[i] << " ";
  }
  return 0;
}
