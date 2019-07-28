#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
#define endl '\n'

class UnionFind {
  private: vector<int> p, rank;
  public:

    UnionFind(int N) {
      rank.assign(N,0);
      p.assign(N,0);
      for (int i = 0; i < N; i++) {
        p[i] = i;
      }
    }

    int findSet(int i) {
      return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j) {
      return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {
      if (!isSameSet(i,j)) {
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) p[y] = x;
        else {
          p[x] = y;
          if (rank[x] == rank[y]) rank[y]++;
        }
      }
    }

    void showSet() {
      for (int i = 0; i < p.size(); i++) {
        cout << p[i] << endl;
      }
    }
};


struct Edge {
  int src, dest;
};

struct Graph {
  int V, E;
  struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
  struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
  graph->V = V;
  graph->E = E;

  graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );

  return graph;
}

bool hasCycle(Graph* graph, UnionFind &uf) {

  for(int i = 0; i < graph->E; i++){

    dbg(i);

    uf.showSet();
    if (uf.isSameSet(graph->edge[i].src, graph->edge[i].dest)) return true;
    uf.unionSet(graph->edge[i].src, graph->edge[i].dest);
  }

  return false;
}

int main(void){
  int n, nodes, u, v;
  bool ans;
  cin >> n; // líneas de entrada
  cin >> nodes; // cantidad de nodos
  UnionFind uf(nodes);
  struct Graph* graph = createGraph(nodes, n);

  uf.showSet();

  for(int i = 0; i < n; i++){
    cin >> u >> v;
    graph->edge[u].src = v;
    graph->edge[v].dest = u;
  }

  ans = hasCycle(graph, uf);
  if (ans) cout << "Existe al menos un ciclo" << endl;
  else cout << "No tiene ciclos" << endl;
  return 0;
}
