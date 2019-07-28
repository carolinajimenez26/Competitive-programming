#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
#define endl '\n'

void bfs(vector<int> G[], bool visitados[], int source){
  cout << "BFS : " << endl;
  queue<int> q;
  visitados[source] = true;
  q.push(source);

  while(!q.empty()){
    int v = q.front();
    q.pop();
    dbg(v);
    for(int i = 0; i < G[v].size(); i++){
      int nv = G[v][i];
      dbg(nv);
      if(!visitados[nv]){
        visitados[nv] = true;
        q.push(nv);
      }
    }
  }
  cout << endl;
}

int main(){
  int n, nodes, u, v, src;
  cin >> n; // número de conexiones
  cin >> nodes;
  vector<int> G[nodes];
  bool visitados[nodes];
  memset(&visitados,0,sizeof(bool)*nodes);
  for(int i = 0; i < n; i++){
    cin >> u >> v;
    if (i == 0) src = u;
    G[u].push_back(v);
  }
  bfs(G,visitados,src);
  return 0;
}
