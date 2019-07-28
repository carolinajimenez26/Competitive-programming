#include <bits/stdc++.h>
using namespace std;

int main(void){
  int N, cont = 0, sum = 0;
  while(true){
    cin >> N;
    if (N == 0) break;
    while(cont < 5){
      if (N % 2 == 0){
        cont++;
        sum += N;
      }
      N++;
    }
    cout << sum << endl;
    cont = 0;
    sum = 0;
  }
  return 0;
}
