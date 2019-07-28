#include <bits/stdc++.h>
using namespace std;

int main(void){
  int n, N[10];
  cin >> n;
  N[0] = n;
  for(int i = 1; i < 10; i++){
    N[i] = N[i-1] * 2;
  }
  for(int i = 0; i < 10; i++){
    cout << "N[" << i << "] = "<< N[i] << endl;
  }
  return 0;
}
