#include <bits/stdc++.h>
using namespace std;

int main(void){
  int i = 1, j = 7, aux_i = 0, aux_j = 0;
  for(int k = 0; k < 5*3; k++){
    if (aux_i == 3){
      i += 2;
      aux_i = 0;
    }
    if (aux_j == 3){
      j = 7;
      aux_j = 0;
    }
    cout << "I=" << i << " J=" << j << endl;
    aux_i++; aux_j++;
    j--;
  }
}
