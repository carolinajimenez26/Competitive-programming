// http://www.spoj.com/problems/GSS1/
// Can you answer these queries I

#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
  vector<int> st, A;
  int n;

  int left (int p) { return p << 1; }
  int right (int p) { return (p << 1) + 1; }

  void build (int p, int L, int R) { // O(n)
    if (L == R) st[p] = L;
    else {
      build(left(p), L, (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R);
      int p1 = st[left(p)], p2 = st[right(p)];
      st[p] = (A[p1] >= A[p2]) ? p1 : p2;
    }
  }

  // Range Maximum Query
  int rmq (int p, int L, int R, int i, int j) { // O(log n)
    if (i > R || j < L) return -1;
    if (L >= i and R <= j) return st[p];

    int p1 = rmq(left(p), L, (L + R) / 2, i, j);
    int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);

    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    return (A[p1] >= A[p2]) ? p1 : p2;
  }

public:

  SegmentTree (const vector<int> &_A) {
    A = _A;
    n = (int)A.size();
    st.assign(4 * n, 0);
    build(1, 0, n - 1);
  }

  int rmq (int i, int j) {
    return rmq(1, 0, n - 1, i, j);
  }
};

int main(void) {
  int N, x, M, y;
  vector<int> A;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> x;
    A.push_back(x);
  }
  SegmentTree st(A);
  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> x >> y;
    x--; y--;
    cout << (st.rmq(x, y) + 1) << endl;
  }
  return 0;
}
