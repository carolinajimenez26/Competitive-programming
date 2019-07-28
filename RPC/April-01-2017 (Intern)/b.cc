#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define dbg(x) cout << #x << ": " << x << endl;
int inf = numeric_limits<int>::max();

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  long long int t, n, k, cnt, mn, tiempo, step, mint, ss;
  string medicamento;
  cin >> t;
  while(t--){
    vector<pair<string,int> > info;
    step = mint = inf;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> medicamento >> tiempo;
      info.push_back(make_pair(medicamento, tiempo));
      if (tiempo < mint) {
        mint = tiempo;
      } if (i != 0) {
        step = gcd(tiempo, step);
      }else{
        step = tiempo;
      }
    }
    ss = mint;
    while (true) {
      for (int i = 0; i < info.size(); i++) {
        if (ss % info[i].second == 0) {
          cout << ss << " " << info[i].first << endl;
          k--;
        }
        if (k == 0) break;
      }
      if (k == 0) break;
      ss += step;
    }
  }
  return 0;
}
