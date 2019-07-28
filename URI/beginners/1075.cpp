#include <bits/stdc++.h>
using namespace std;

int main(void){
  int N;
  cin >> N;
  for(int i = 1; i <= 10000; i++){
    if (i % N == 2) cout << i << endl;
  }
  return 0;
}
