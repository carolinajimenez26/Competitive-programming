#include <bits/stdc++.h>
using namespace std;

int main(void){
  int n, X[10];
  for(int i = 0; i < 10; i++){
    cin >> n;
    n > 0 ? X[i] = n : X[i] = 1;
  }
  for(int i = 0; i < 10; i++){
    cout << "X[" << i << "] = " << X[i] << endl;
  }
  return 0;
}
