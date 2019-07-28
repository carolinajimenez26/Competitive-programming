#include <bits/stdc++.h>
using namespace std;
#define sz 100005

int x[sz], y[sz];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, mx, my;
  long long int s;
  while(cin >> n){
    s = 0;
    memset(x, 0, sizeof x);
    memset(y, 0, sizeof y);
    for(int i=0; i<n; i++){
      cin >> x[i] >> y[i];
    }
    sort(x, x+n);
    sort(y, y+n);
    mx = x[n/2];
    my = y[n/2];
    for(int i=0; i<n; i++){
      if(i != n/2)
        s += abs(mx - x[i]) + abs(my - y[i]);
    }
    cout << s << endl;
  }
  return 0;
}
