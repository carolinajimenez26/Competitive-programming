#include <bits/stdc++.h>
using namespace std;

int main(void){
  int N, pos, maxn = numeric_limits<int>::min();
  for(int i = 1; i <= 100; i++){
    cin >> N;
    if (N >= maxn) {
      maxn = N;
      pos = i;
    }
  }
  cout << maxn << endl << pos << endl;
  return 0;
}
