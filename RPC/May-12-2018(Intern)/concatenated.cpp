#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define MAX 10000010
bool S[MAX];

long long int tonum(string &s) {
  stringstream ss;
  ss << s;
  long int out;
  ss >> out;
  return out;
}

void sieve() {
  S[0] = S[1] = 0;
  for (long long int i = 2; i < MAX; i++) {
    if (S[i]) {
      for (long long int j = i * i; j < MAX; j += i) {
        S[j] = 0;
      }
    }
  }
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  memset(S, 1, sizeof(S));
  int k;
  string tmp;
  string n_s;
  sieve();
  bool flag;
  while(cin >> k) {
    cin >> n_s;
    flag = true;
    for (long long int i = 0; i < n_s.size(); i += k) {
      tmp = "";
      for (int j = 0; j < k; j++) {
        tmp.push_back(n_s[i + j]);
      }
      // cout << "tmp: " << tmp << endl;
      // cout << "tonum: " << tonum(tmp) << endl;
      // cout << "prime?: " << S[tonum(tmp)] << endl;
      if (!S[stoi(tmp)]) {
        cout << ":(" << endl;
        flag = false;
        break;
      }
    }
    // cout << "flag: " << flag << endl;
    if (flag) cout << ":)" << endl;
  }
  return 0;
}
