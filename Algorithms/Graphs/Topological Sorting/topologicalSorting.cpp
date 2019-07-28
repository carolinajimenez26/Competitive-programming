#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
#define endl '\n'

void printStack(stack<int> s) {
  cout << "printStack" << endl;
  while (!s.empty()) {
    dbg(s.top());
    s.pop();
  }
}

void printGraph(vector<int> G[], int size) {
  cout << "printGraph" << endl;
  for(int i = 0; i < size; i++){
    dbg(i);
    for (auto item : G[i]) {
      dbg(item);
    }
  }
}

void dfs(vector<int> G[], int node, bool *visited, stack<int> &st) {
  cout << "dfs" << endl;

  visited[node] = true;
  for (auto nv : G[node]) {
    if (!visited[nv]) dfs(G, nv, visited, st);
  }
  st.push(node);
}

stack<int> TopoSort(vector<int> G[], bool *visited, int source, int V){
  cout << "TopoSort" << endl;
  stack<int> st;

  for (int i = 0; i < V; i++) {
    if (!visited[i]) dfs(G, i, visited, st);
  }

  return st;
}

int main(){
  int n, nodes, u, v, src;
  cin >> n; // número de conexiones
  cin >> nodes;
  vector<int> G[nodes];
  bool visited[nodes];
  memset(&visited,0,sizeof(bool)*nodes);
  for(int i = 0; i < n; i++){
    cin >> u >> v;
    if (i == 0) src = u;
    G[u].push_back(v);
  }
  // printGraph(G,nodes);
  stack<int> ans = TopoSort(G, visited, src, nodes);
  printStack(ans);
  return 0;
}
