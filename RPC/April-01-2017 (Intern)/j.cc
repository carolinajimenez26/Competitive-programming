#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl;
#define MAX 133000
#define MAXX 266000
#define endl '\n'

vector<long int> ulams;

void UlamsN() {
  long int tmp[MAXX], p = 0;
  memset(tmp, 0, sizeof tmp);
  tmp[1] = tmp[2] = 1;
  for (int i = 2; i < MAX; i++) {
    if (tmp[i] != 1) continue;
    for (int j = 1; j < i; j++) {
      if (tmp[i] != 1 or tmp[j] != 1) continue;
      p = i + j;
      tmp[p]++;
    }
  }
  for (int k = 0; k < MAXX; k++) {
    if (tmp[k] == 1) {
      ulams.push_back(k);
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int cases, n;
  cin >> cases;
  UlamsN();
  while (cases-- > 0) {
    cin >> n;
    cout << ulams[n-1] << endl;
  }
  return 0;
}
