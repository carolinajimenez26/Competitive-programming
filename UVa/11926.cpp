#include <bits/stdc++.h>
using namespace std;
#define N 1000002
bitset<N> tasks;

int main(void) {
  int n, m; // one time tasks and repeting tasks
  int start, end, repetition;
  bool overlap;
  while (cin >> n >> m) {
    if (!n and !m) break;
    overlap = false;
    tasks.reset();
    for (int i = 0; i < n; i++) {
      cin >> start >> end;
      for (int j = start; j < end; j++) {
        if (tasks.test(j)) overlap = true;
        tasks.set(j,1);
      }
    }

    for (int i = 0; i < m; i++) {
      cin >> start >> end >> repetition;
      if (!overlap) {
        int tmp = start;
        for (int k = 0; k < N and !overlap; k += repetition) {
          for (int j = start; j < end; j++) {
            if (j + k < N) {
              if (tasks.test(j + k)) {
                overlap = true;
                break;
              }
              tasks.set(j + k, 1);
            }
          }
        }
      }
    }
    cout << (overlap ? "CONFLICT" : "NO CONFLICT") << endl;
  }

  return 0;
}
