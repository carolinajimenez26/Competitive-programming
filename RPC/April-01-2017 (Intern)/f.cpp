#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  long long int x;
  cin >> t;
  while(t-- > 0){
    long long int s;
    cin >> s;
    x = s * s + 2 * s;
    cout << x << endl;
  }
  return 0;
}
