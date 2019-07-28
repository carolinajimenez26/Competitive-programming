#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl

void getOrder(int node, vector<int> &visited, vector<int> &order,
              vector<vector<int> > &g) {
  visited[node] = 1;
  for (auto neigh : g[node]) {
    if (visited[neigh] == 0) {
      getOrder(neigh, visited, order, g);
    }
  }
  order.push_back(node);
}

void getComponents(int node, vector<int> &visited,
                   vector<int> &components,
                   vector<vector<int> > &g) {
  visited[node] = true;
  for (auto neigh : g[node]) {
    if (!visited[neigh]) {
      getComponents(neigh, visited, components, g);
    }
  }
  components.push_back(node);
}

void connectComponents(int node, vector<int> &visited, vector<vector<int> > g,
                       vector<vector<int> > &sub_g, map<int, int> components,
                       vector<int> &visited_components) {
  visited[node] = 1;
  visited_components[components[node]] = 1;
  for (auto neigh : g[node]) {
    if (components[node] != components[neigh]) {
      sub_g[components[node]].push_back(components[neigh]);
    }
    if (visited[neigh] == 0) {
      connectComponents(neigh, visited, g, sub_g, components, visited_components);
    }
  }
}

void addSubComponents(int index, vector<int> &sub_components, map<int, int> &components) {
  for (auto e : sub_components) {
    components[e] = index;
  }
}

void print(vector<vector<int> > vvi) {
  for (int i = 0; i < vvi.size(); i++) {
    cout << i << " -> ";
    for (auto e : vvi[i]) {
      cout << e << " ";
    }
    cout << endl;
  }
}

void print(map<int, int> m) {
  for (auto e : m) {
    cout << e.first << " -> " << e.second << endl;
  }
}

void print(vector<int> v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

int main(void) {
  int nodes, edges, x, y;
  cin >> nodes >> edges;

  vector<vector<int> > g(nodes), gr(nodes), sub_g;
  vector<int> order(nodes), visited(nodes, 0), sub_components, empty, visited_components;
  map<int, int> components;

  for (int i = 0; i < edges; i++) {
    cin >> x >> y;
    x--; y--;
    g[x].push_back(y);
    gr[y].push_back(x);
  }
  // print(g);
  for (int i = 0; i < nodes; i++) {
    if (visited[i] == 0) {
      getOrder(i, visited, order, g);
    }
  }
  // print(visited);
  visited.assign(visited.size(), 0);
  // print(visited);
  int j = 0;
  for (int i = order.size() - 1; i >= 0; i--) {
    if (!visited[order[i]]) {
      sub_components.clear();
      getComponents(order[i], visited, sub_components, gr);
      addSubComponents(j, sub_components, components);
      j++;
    }
  }
  print(components);
  cout << endl;
  visited.assign(visited.size(), 0);
  // dbg(j);
  visited_components.assign(j, 0);
  j--;
  sub_g.assign(j, empty);
  for (int i = 0; i < nodes; i++) {
    if (visited[i] == 0) {
      connectComponents(i, visited, g, sub_g, components, visited_components);
    }
  }
  print(sub_g);
  return 0;
}
