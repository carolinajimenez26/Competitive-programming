#include <bits/stdc++.h>
using namespace std;

int main(void){
  float n;
  int negative = 0, positive = 0;
  for(int i = 0; i < 6; i++){
    cin >> n;
    if(n < 0) negative++;
    else positive++;
  }
  cout << positive <<" valores positivos" << endl;
  return 0;
}
