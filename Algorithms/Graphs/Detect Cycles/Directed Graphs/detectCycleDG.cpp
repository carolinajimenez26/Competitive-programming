//Detect Cycle in a Directed Graph
#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
#define endl '\n'

bool dfs(vector<int> G[], int curr, set<int> &whites, set<int> &grays, set<int> &blacks) {

  whites.erase(curr);
  grays.insert(curr);

  for(auto item : G[curr]) {
    if (blacks.count(item)) continue;
    if (grays.count(item)) return true;
    if (dfs(G, item, whites, grays, blacks)) return true;
  }

  grays.erase(curr);
  blacks.insert(curr);
  return false;
}

bool hasCycle(vector<int> G[], set<int> &whites){
  set<int> grays;
  set<int> blacks;

  while (whites.size() > 0) {
    int curr = *(whites.begin());
    if(dfs(G, curr, whites, grays, blacks)) {
      return true;
    }
  }
  return false;
}

int main(){
  int n, nodos, u, v;
  bool ans;
  cin >> n; // número de conexiones
  cin >> nodos;
  vector<int> G[nodos];
  set<int> whites;
  for(int i = 0; i < n; i++){
    cin >> u >> v;
    G[u].push_back(v);
    whites.insert(u);
    whites.insert(v);
  }
  // for (auto item : whites)
  //   cout << item << endl;

  // for(int i = 0; i < size; i++){
  //   for (auto item : G[i]) {
  //     cout << item << endl;
  //   }
  // }

  ans = hasCycle(G,whites);
  if (ans) cout << "Existe al menos un ciclo" << endl;
  else cout << "No tiene ciclos" << endl;
  return 0;
}
