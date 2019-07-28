#include <bits/stdc++.h>
using namespace std;

int main(void){
  int A, N, sum = 0;
  bool flag = true;
  cin >> A;
  while(flag){
    cin >> N;
    if (N > 0) flag = false;
  }
  for(int i = 0; i < N; i++, A++){
    sum += A;
  }
  cout << sum << endl;
  return 0;
}
