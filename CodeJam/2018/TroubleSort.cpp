#include <bits/stdc++.h>
using namespace std;
long int L[100001];

void troubleSort(long int N) {
  bool done = false;
  long int tmp;
  while (not done) {
    done = true;
    for (long int i = 0; i < N - 2; i++) {
      if (L[i] > L[i + 2]) {
        done = false;
        tmp = L[i];
        L[i] = L[i + 2];
        L[i + 2] = tmp;
      }
    }
  }
}

long int find(long int N) {
  for (long int i = 0; i < N - 1; i++) {
    if (L[i] > L[i + 1]) return i;
  }
  return -1;
}

void print(long int N) {
  for (long int i = 0; i < N; i++) {
    cout << L[i] << " ";
  }
  cout << endl;
}

int main(void) {
  int T;
  long int N, x = 1;
  long int ans;
  cin >> T;
  while (T--) {
    cin >> N;
    for (long int i = 0; i < N; i++) {
      cin >> L[i];
    }
    // print(N);
    troubleSort(N);
    // print(N);
    ans = find(N);
    if (ans == -1) cout << "Case #" << x << ": OK" << endl;
    else cout << "Case #" << x << ": " << ans << endl;
    x++;
  }
  return 0;
}
