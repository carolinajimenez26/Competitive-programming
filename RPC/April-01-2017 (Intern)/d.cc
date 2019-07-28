#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define dbg(x) cout << #x << ": " << x << endl;

int sum_div(int x){
  int sum = 1;
  for(int i=2; i<x; i++){
    if(x % i == 0) sum+=i;
  }
  return sum;
}

int main(){
  int t, n, pv;
  cin >> t;
  while(t--){
    cin >> n;
    pv = sum_div(n);
    if(pv < n)
      cout << "deficient" << endl;
    else if(pv == n)
      cout << "perfect" << endl;
    else
      cout << "abundant" << endl;
  }
  return 0;
}
