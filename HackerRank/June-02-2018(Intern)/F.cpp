#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
// #define INF numeric_limits<int>::max()

void prefix_sum(vector<int> &A, vector<int> &A_sum) {
  A_sum.push_back(A[0]);
  int sum = A[0];
  for (int i = 1; i < A.size(); i++) {
    sum += A[i];
    A_sum.push_back(sum);
  }
}

void print(vector<int> A) {
  cout << "--------" << endl;
  for (int i = 0; i < A.size(); i++) {
    cout << A[i] << " ";
  }
  cout << endl;
}

int main(void) {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  int n, x, q, l, r;
  vector<int> ships, wolves, ships_sum, wolves_sum;
  while (cin >> n) {
    ships.clear();
    wolves.clear();
    ships_sum.clear();
    wolves_sum.clear();
    for (int i = 0; i < n; i++) {
      cin >> x;
      if (x == 1) {
        ships.push_back(1);
        wolves.push_back(0);
      }
      else {
        ships.push_back(0);
        wolves.push_back(1);
      }
    }
    prefix_sum(ships, ships_sum);
    prefix_sum(wolves, wolves_sum);
    // print(wolves);
    // print(wolves_sum);
    cin >> q;
    for (int i = 0; i < q; i++) {
      cin >> l >> r;
      l--;
      r--;
      if (l >= 1) {
        if (ships_sum[r] - ships_sum[l - 1] < wolves_sum[r] - wolves_sum[l - 1]) {
          cout << "Yes" << endl;
        } else cout << "No" << endl;
      } else {
        if (ships_sum[r] - 0 < wolves_sum[r] - 0) {
          cout << "Yes" << endl;
        } else cout << "No" << endl;
      }
    }
  }
  return 0;
}
