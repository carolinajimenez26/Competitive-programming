#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
#define endl '\n'

bool isBipartite(vector<int> G[], int source, int color[]){
  queue<int> q;
  color[source] = 1;
  q.push(source);

  while(!q.empty()){
    int v = q.front();
    q.pop();
    // dbg(v);
    // dbg(color[v]);

    for(auto nv : G[v]){
      // dbg(nv);
      // dbg(color[nv]);
      if(color[nv] == -1){
        color[nv] = 1 - color[v]; // different color of the parent
        q.push(nv);
      } else if (color[v] == color[nv]) return false; // parent and child has the same color
    }
  }
  return true;
}

int main(){
  int n, nodes, u, v, src;
  cin >> n >> nodes;
  vector<int> G[nodes];
  int color[nodes];
  memset(&color,-1,sizeof(int)*nodes);
  for(int i = 0; i < n; i++){
    cin >> u >> v;
    if (i == 0) src = u;
    G[u].push_back(v);
  }
  isBipartite(G,src, color) ? cout << "Es bipartito" << endl : cout << "No es bipartito";
  return 0;
}
