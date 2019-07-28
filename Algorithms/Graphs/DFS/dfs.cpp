#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
#define endl '\n'

void dfs(vector<int> G[], bool visitados[], int source){
  cout << "DFS : " << endl;
  stack<int> st;
  visitados[source] = true;
  st.push(source);

  while(!st.empty()){
    int v = st.top();
    st.pop();
    dbg(v);
    for(int i = 0; i < G[v].size(); i++){
      int nv = G[v][i];
      dbg(nv);
      if(!visitados[nv]){
        visitados[nv] = true;
        st.push(nv);
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
  dfs(G,visitados,src);
  return 0;
}
