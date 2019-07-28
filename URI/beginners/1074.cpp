#include <bits/stdc++.h>
using namespace std;

int main(void){
  int N, number;
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> number;
    if (number == 0) cout << "NULL";
    else {
      if (number % 2 == 0) cout << "EVEN ";
      else cout << "ODD ";
      if (number > 0) cout << "POSITIVE";
      else cout << "NEGATIVE" ;
    }
    cout << endl;
  }
  return 0;
}
