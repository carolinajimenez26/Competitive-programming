#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
const int MAX = 100010;
int v[MAX];
int frec[60][MAX];
int prefix[60][MAX];

int howMany(int l, int r) {
  int sum = 0;
  for (int i = 0; i < 60; i++) {
    int tmp = 0;
    if (l != 0) {
      tmp = prefix[i][l - 1];
    }
    sum += (prefix[i][r] - tmp) % 2;
  }
  return sum;
}

void calc(int size) {
  for (int i = 0; i < 60; i++) {
    for (int j = 0; j < size; j++) {
      if (v[j] == (i + 1)) frec[i][j] = 1;
      else frec[i][j] = 0;
    }
  }
}

void prefix_sum(int len) {
  for (int j = 0; j < 60; j++) {
    int sum = frec[j][0];
    prefix[j][0] = frec[j][0];
    for (int i = 1; i < len; i++) {
      sum += frec[j][i];
      prefix[j][i] = sum;
    }
  }
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, n, q, l, r;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    calc(n);
    prefix_sum(n);
    cin >> q;
    for (int i = 0; i < q; i++) {
      cin >> l >> r;
      cout << howMany(l - 1, r - 1) << endl;
    }
  }
  return 0;
}
