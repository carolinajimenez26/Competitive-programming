#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
#define INF numeric_limits<int>::max()

void print(map<int, vector<int>> m) {
  for (auto e : m) {
    cout << "e " << e.first << " -> ";
    for (auto i : e.second) {
      cout << i << " ";
    }
    cout << endl;
  }
}

void print(vector<int> v) {
  for (auto e : v) {
    cout << e << " ";
  }
  cout << endl;
}

int find(int node, vector<int> visited, map<int, vector<int>> m) {
  queue<int> s;
  s.push(node);
  visited[node] = 1;
  int ans = 0;
  while (!s.empty()) {
    int e = s.front();
    s.pop();
    for (int i = 0; i < m[e].size(); i++) {
      if (visited[m[e][i]] == 0) {
          visited[(m[e][i])] = 1;
          s.push(m[e][i]);
          ans++;
      }
    }
  }
  return ans;
}

int main(void) {
  int n, m, a, b, q, x;
  map<int, vector<int>> mymap;
  cin >> n >> m;
  vector<int> visited(n, 0);
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    mymap[a - 1].push_back(b - 1);
  }
  // print(mymap);
  // print(visited);
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> x;
    x--;
    cout << find(x, visited, mymap) << endl;
  }
  return 0;
}
