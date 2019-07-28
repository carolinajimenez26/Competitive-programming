#include <bits/stdc++.h>
using namespace std;

int main(void){
  int N, m, in = 0, out = 0;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> m;
    if (m >= 10 && m <= 20) in++;
    else out++;
  }
  cout << in << " in" << endl;
  cout << out << " out" << endl;
  return 0;
}
