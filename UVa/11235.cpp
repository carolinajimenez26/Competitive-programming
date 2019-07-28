#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define COUNT 10
#define dbg(x) cout << #x << ": " << x << endl
const int inf = 100001;

class SegmentTree {
private:
  vector<int> st, A;
  int n;

  int left (int p) { return p << 1; }
  int right (int p) { return (p << 1) + 1; }

  void build (int p, int L, int R) { // O(n)
    if (L == R) {
      st[p] = L;
    } else {
      build(left(p), L, (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R);
      int p1 = st[left(p)], p2 = st[right(p)];
      st[p] = (A[p1] >= A[p2]) ? p1 : p2;
    }
  }

  // Range Maximum Query
  int query (int p, int L, int R, int i, int j) { // O(log n)
    if (i > R || j < L) return inf;
    if (L >= i and R <= j) return st[p];

    int p1 = query(left(p), L, (L + R) / 2, i, j);
    int p2 = query(right(p), (L + R) / 2 + 1, R, i, j);
    if (p1 == inf) return p2;
    if (p2 == inf) return p1;
    return (A[p1] >= A[p2]) ? p1 : p2;
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

  SegmentTree (const vector<int> &_A) {
    A = _A;
    n = (int)A.size();
    st.assign(4 * n, 0);
    build(1, 0, n - 1);
  }

  int query (int i, int j) {
    return query(1, 0, n - 1, i, j);
  }

  void print () {
    print(1, 0, n - 1, 0);
  }
};

void print(vector<int> v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

void print(map<int, int> m) {
  for (auto e : m) cout << e.first << " -> " << e.second << endl;
}

int main(void) {
  int n, q, x, y, tmp, j, b_size, max_pos, value, k;
  vector<int> A, B, C; // original, frecuencies, start-end values
  map<int, int> decode;
  while (cin >> n) {
    if (n == 0) break;
    cin >> q;
    b_size = 1;
    A.assign(n, 0);
    B.assign(n, 0);
    C.assign(n, 0);
    decode.clear();
    cin >> tmp;
    A[0] = tmp;
    B[0] = 1;
    j = 0; k = 0;
    decode[0] = 0; // A[0] = B[0]
    for (int i = 1; i < n; i++) {
      cin >> A[i];
      if (A[i] == tmp) {
        B[j] += 1;
      } else {
        tmp = A[i];
        j++;
        B[j] = 1;
        b_size++;
        C[k] = i - 1;
        k++;
      }
      decode[i] = j;
    }
    C[b_size - 1] = A.size() - 2;
    B.resize(b_size);
    C.resize(b_size);
    // print(A);
    // print(B);
    // print(decode);
    // print(C);
    SegmentTree st(B);
    // st.print();
    for (int i = 0; i < q; i++) {
      cin >> x >> y;
      x--; y--;
      int left = decode[x], right = decode[y];
      int amount_left = C[left] - x + 1;
      int amount_right = y - ((right - 1 < 0 ? 0 : C[right - 1]) + 1) + 1;
      if (left == right) {
        cout << (y - x + 1) << endl;
      } else {
        if (left + 1 == right) {
          cout << max(amount_left, amount_right) << endl;
        } else {
          int middle = st.query(decode[x] + 1, decode[y] - 1);
          int amount_middle = B[middle];
          cout << max(amount_middle, max(amount_left, amount_right)) << endl;
        }
      }
    }
  }
  return 0;
}
