#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
int const MAX = 10000;
bool bs[MAX];

void sieve() {
  bs[0] = bs[1] = 0;
  for (int i = 2; i < MAX; i++) {
    if (bs[i]) {
      // dbg(i);
      // cout << "HOLA" << endl;
      for (int j = i * i; j < MAX; j += i) {
        bs[j] = 0;
      }
    }
  }
}

bool prime(vector<char> v) {
  string tmp = "";
  // dbg(atoi("00000000123"));
  for (int i = 0; i < v.size(); i++) {
    tmp.push_back(v[i]);
  }
  if (tmp[0] == '0') return false;
  int n = stoi(tmp);
  // dbg(n);
  // dbg(bs[n]);
  return bs[n];
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // cout << "heeey" << endl;
  memset(bs, 1, sizeof(bs));
  sieve();
  // for (int i = 0; i < 10; i++) {
  //   cout << bs[i] << " ";
  // }
  // cout << endl;
  int t;
  string n;
  cin >> t;
  vector<char> v;
  while (t--) {
    v.clear();
    bool isprime = false;
    cin >> n;
    for (int i = 0; i < n.size(); i++) {
      v.push_back(n[i]);
    }
    sort(v.begin(), v.end());
    do {
      isprime = prime(v);
      if (isprime) break;
    } while(next_permutation(v.begin(),v.end()));
    isprime = prime(v);

    if (isprime) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
