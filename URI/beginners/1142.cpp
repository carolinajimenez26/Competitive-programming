#include <bits/stdc++.h>
using namespace std;

int main(void){
  int n, aux = 1;
  cin >> n;
  while(n--) {
    for(int i = 0; i < 3; i++) cout << aux++ << " ";
    cout << "PUM" << endl;
    aux++;
  }
  return 0;
}
