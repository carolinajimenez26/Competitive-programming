#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
#define endl '\n'

bool dfs(vector<int> G[], bool visited[], int source, int parent[]){
  cout << "DFS : " << endl;
  stack<int> st;
  visited[source] = true;
  parent[source] = -1;
  st.push(source);

  while(!st.empty()){
    int v = st.top();
    st.pop();
    dbg(v);
    for(auto nv : G[v]){
      parent[nv] = v;
      dbg(nv);
      if(!visited[nv]){
        visited[nv] = true;
        st.push(nv);
      } else if (parent[nv] != nv) {
        return true;
      }
    }
  }
  return false;
}

int main(){
  int n, nodes, u, v, src;
  cin >> n; // número de conexiones
  cin >> nodes;
  vector<int> G[nodes];
  bool visited[nodes];
  int parent[nodes];
  memset(&parent,-1,sizeof(int)*nodes);
  memset(&visited,0,sizeof(bool)*nodes);
  for(int i = 0; i < n; i++){
    cin >> u >> v;
    if (i == 0) src = u;
    G[u].push_back(v);
  }
  dfs(G,visited,src,parent) ? (cout << "Tiene ciclos") : (cout << "No tiene ciclos");
  return 0;
}
