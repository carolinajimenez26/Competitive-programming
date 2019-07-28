#include <bits/stdc++.h>
using namespace std;

bool PerfectNumber(int N){
  int sum = 0;
  for (int i = 1; i < N; i++) {
    if (N % i == 0) sum += i;
  }
  return sum == N;
}

int main(void){
  int cases, X;
  cin >> cases;
  while (cases--) {
    cin >> X;
    if (PerfectNumber(X)) cout << X << " eh perfeito" << endl;
    else cout << X << " nao eh perfeito" << endl;
  }
  return 0;
}
