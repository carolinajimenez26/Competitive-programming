#include <bits/stdc++.h>
using namespace std;
#define COUNT 10
#define dbg(x) cout << #x << ": " << x << endl

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
      st[p] = (A[p1] <= A[p2]) ? p1 : p2;
    }
  }

  // Range Minimum Query
  int rmq (int p, int L, int R, int i, int j) { // O(log n)
    if (i > R || j < L) return -1;
    if (L >= i and R <= j) return st[p];

    int p1 = rmq(left(p), L, (L + R) / 2, i, j);
    int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);

    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    return (A[p1] <= A[p2]) ? p1 : p2;
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
  SegmentTree () {}

  SegmentTree (const vector<int> &_A) {
    A = _A;
    n = (int)A.size();
    st.assign(4 * n, 0);
    build(1, 0, n - 1);
  }

  int rmq (int i, int j) {
    return rmq(1, 0, n - 1, i, j);
  }

  void print () {
    print(1, 0, n - 1, 0);
  }
};

void print(vector<int> v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

struct LCA {
  vector<int> euler, height, visited, first;
  SegmentTree tree;

  LCA(vector<vector<int> > &g, int source) {
    visited.resize(g.size());
    first.resize(g.size());
    dfs(g, source);
    // print(euler);
    // print(height);
    // print(first);
    tree = SegmentTree(height);
    // tree.print();
  }

  void dfs(vector<vector<int>> &adj, int node, int h = 0) {
    visited[node] = true;
    first[node] = euler.size();
    euler.push_back(node);
    height.push_back(h);
    for (auto to : adj[node]) {
      if (!visited[to]) {
        dfs(adj, to, h + 1);
        euler.push_back(node);
        height.push_back(h);
      }
    }
  }

  void swap(int &A, int &B) {
    int tmp = A;
    A = B;
    B = tmp;
  }

  int lca(int u, int v) {
    int left = first[u], right = first[v];
    if (left > right)
      swap(left, right);
    // dbg(left); dbg(right);
    // dbg(tree.rmq(left, right));
    return euler[tree.rmq(left, right)];
  }
};

int main() {
  int tc, n, m, q, v, w, c = 1, x;
  cin >> tc;
  vector<vector<int> > g;
  while (tc--) {
    cin >> n;
    g.clear();
    g.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> m;
      for (int j = 0; j < m; j++) {
        cin >> x;
        x--;
        g[i].push_back(x);
      }
    }
    LCA lca(g, 0);
    cin >> q;
    cout << "Case " << c << ":" << endl;
    for (int i = 0; i < q; i++) {
      cin >> v >> w;
      v--; w--;
      cout << (lca.lca(v, w) + 1) << endl;
    }
    c++;
  }
  return 0;
}
