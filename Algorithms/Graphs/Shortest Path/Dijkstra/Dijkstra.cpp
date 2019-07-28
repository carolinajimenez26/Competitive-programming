#include <bits/stdc++.h>
using namespace std;
#define Node pair<int, int> // v, w
const int INF = numeric_limits<int>::max();
#define dbg(x) cout << #x << ": " << x << endl

struct cmp {
  bool operator() ( const int &a , const int &b ) {
    return a > b;
  }
};

void dijkstra(vector<Node> graph[], int src, vector<int> &parent, vector<int> &distances) {
  priority_queue<int, vector<int>, cmp> Q;
  Q.push(src);
  distances[src] = 0;
  int u, w;
  while (!Q.empty()) {
    u = Q.top();
    Q.pop();
    // dbg(u);
    for (auto neigh : graph[u]) {
      // dbg(neigh.first);
      w = neigh.second;
      if (distances[u] + w < distances[neigh.first]) {
        distances[neigh.first] = distances[u] + w;
        parent[neigh.first] = u;
        Q.push(neigh.first);
      }
    }
  }
}

void print(int u, vector<int> parent) {
  if (parent[u] != -1) {
    print(parent[u], parent);
  }
  cout << u << endl;
}

void print(vector<int> v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

void print(vector<bool> v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

int main(void) {
  int nodes, edges, u, v, w;
  cin >> nodes >> edges;

  vector<Node> graph[nodes];
  vector<int> parent(nodes, -1), distances(nodes, INF);

  for (int i = 0; i < edges; i++) {
    cin >> u >> v >> w;
    u--; v--; // 0 index
    graph[u].push_back(make_pair(v, w));
  }
  // print(visited);
  dijkstra(graph, 0, visited, parent, distances);
  // for (int i = 0; i < nodes; i++) {
  //   print(i, parent);
  //   cout << endl;
  // }
  // print(visited);
  print(parent);
  print(distances);
  return 0;
}
