#include <bits/stdc++.h>
using namespace std;

int maior(int A, int B){
  return (A + B + abs(A - B) ) / 2;
}

int main(void){
  int A, B, C;
  cin >> A >> B >> C;
  cout << maior(A,maior(B,C)) << " eh o maior" << endl;
  return 0;
}
