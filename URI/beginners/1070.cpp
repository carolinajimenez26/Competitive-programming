#include <bits/stdc++.h>
using namespace std;

int main(void){
  int x, cont = 6;
  cin >> x;
  while(cont){
    if (x % 2 != 0){
      cont--;
      cout << x << endl;
    }
    x++;
  }
  return 0;
}
