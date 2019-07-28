#include <bits/stdc++.h>
using namespace std;

int main(void){
  int i = 1, j = 7;
  for(int k = 0; k < 5; k++){
    for(int l = 0; l < 3; l++){
      cout << "I=" << i << " J=" << j << endl;
      j--;
    }
    i += 2;
    j += 5;
  }
  return 0;
}
