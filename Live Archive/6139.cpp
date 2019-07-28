// https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=4150
// Interval Product
#include <bits/stdc++.h>
using namespace std;
#define COUNT 10
#define dbg(x) cout << #x << ": " << x << endl
#define endl '\n'

class SegmentTree {
private:
  vector<int> st, A;
  int n;

  int left(int p) { return p << 1; }
  int right(int p) { return (p << 1) + 1; }

  void build(int p, int L, int R) { // O(n)
    // dbg(L); dbg(R);
    if (L == R) {
      st[p] = A[L];
    } else {
      build(left(p), L, (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R);
      int p1 = st[left(p)], p2 = st[right(p)];
      st[p] = p1 * p2;
    }
  }

  int query(int p, int L, int R, int i, int j) { // O(log n)
    if (i > R || j < L) return -10;
    if (L >= i and R <= j) return st[p];

    int p1 = query(left(p), L, (L + R) / 2, i, j);
    int p2 = query(right(p), (L + R) / 2 + 1, R, i, j);

    if (p1 == -10) return p2;
    if (p2 == -10) return p1;
    return p1 * p2;
  }

  void change(int p, int L, int R, int element_pos) {
    if (R < element_pos || L > element_pos) return;
    if (L == R) {
      st[p] = A[L];
      return;
    }
    else {
      change(left(p), L, (L + R) / 2, element_pos);
      change(right(p), (L + R) / 2 + 1, R, element_pos);
      int p1 = st[left(p)], p2 = st[right(p)];
      st[p] = p1 * p2;
    }
  }

  void print (int p, int L, int R, int space) {
    space += COUNT;
    if (L == R) {
      for (int i = COUNT; i < space; i++)
          printf(" ");

      cout << st[p] << endl;
      return;
    }
    else {
      print(left(p), L, (L + R) / 2, space);

      cout << endl;
      for (int i = COUNT; i < space; i++)
          cout << " ";

      cout << st[p] << endl;

      print(right(p), (L + R) / 2 + 1, R, space);
    }
  }

public:

  SegmentTree(const vector<int> &_A) {
    A = _A;
    n = (int)A.size();
    st.assign(4 * n, 0);
    build(1, 0, n - 1);
  }

  int query(int i, int j) {
    return query(1, 0, n - 1, i, j);
  }

  void change(int element_pos, int element) { // changes an element of the tree
    A[element_pos] = element;
    change(1, 0, n - 1, element_pos);
  }

  void print() {
    print(1, 0, n - 1, 0);
  }
};

void print(vector<int> v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k, x, y, z;
  char c;
  string ans;
  vector<int> A;
  while (cin >> n >> k) {
    A.assign(n, 0);
    ans.clear();
    for (int i = 0; i < n; i++) {
      cin >> x;
      if (x == 0) A[i] = 0;
      if (x > 0) A[i] = 1;
      if (x < 0) A[i] = -1;
      // A[i] = x;
    }
    SegmentTree st(A);
    // print(A);
    // st.print();
    for (int i = 0; i < k; i++) {
      cin >> c >> x >> y;
      x--;
      if (c == 'P') {
        y--;
        z = st.query(x, y);
        if (z == 0) ans.push_back('0');
        else if (z < 0) ans.push_back('-');
        else ans.push_back('+');
        // dbg(ans);
        // dbg(z);
      } else {
        if (y == 0) {
          st.change(x, 0);
          A[x] = 0;
        }
        if (y > 0) {
          st.change(x, 1);
          A[x] = 1;
        }
        if (y < 0) {
          st.change(x, -1);
          A[x] = -1;
        }
        // st.print();
      }
    }
    cout << ans << endl;
  }
  return 0;
}
