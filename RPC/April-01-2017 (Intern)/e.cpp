#include <bits/stdc++.h>
using namespace std;

bitset<32> origin;
bitset<32> elotro;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t, p;
  long int n, m, x;
  cin >> t;
  while(t-- > 0){
    cin >> n >> m >> p;
    x = log2(m)+1;
    origin = n;
    elotro = m;
    for(int i=0; i<x; i++){
      origin[p+i] = elotro[i];
    }
    cout << origin.to_ullong() << endl;
  }
  return 0;
}
