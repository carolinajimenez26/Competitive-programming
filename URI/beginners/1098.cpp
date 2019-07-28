#include <bits/stdc++.h>
using namespace std;

int main(void){
  float i = 0;
  while(i <= 2.2){
    for(int k = 1; k <= 3; k++){
      cout << "I=" << i << " J=" << i + k << endl;
    }
    i += 0.2;
  }
  return 0;
}
