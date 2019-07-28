#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void print(map<int, vector<int> > graph) {
  for (auto& n : graph) {
    cout << n.first << " -> ";
    for (auto& nv : n.second) cout << nv << " ";
    cout << endl;
  }
}

int main(void) {
  long long int n, m, q1, q2, x;
  map<long long int, vector<long long int> > graph;
  while (cin >> n >> m) {
    graph.clear();
    for (long long int i = 1; i <= n; i++) {
      cin >> x;
      graph[x].push_back(i);
    }
    // print(graph);
    for (long long int i = 0; i < m; i++) {
      cin >> q1 >> q2;
      if (graph.count(q2)) {
        if (graph[q2].size() >= q1) {
          cout << graph[q2][q1 - 1] << endl;
        } else cout << 0 << endl;
      } else cout << 0 << endl;
    }
  }
  return 0;
}
