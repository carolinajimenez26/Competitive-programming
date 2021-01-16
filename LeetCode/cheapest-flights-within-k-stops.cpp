#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
  int to, weight;

  void Print() {
    cout << "[to: " << to << ", w: " << weight << "]";
  }
};

struct Node {
  int val;
  vector<Edge> neighs;

  Node(int _val): val(_val) {}

  void Print() {
    cout << val << "->";
    for (auto neigh : neighs) {
      neigh.Print();
    }
    cout << endl;
  }
};

struct Option {
  Node* node;
  int curr_stops, cost;

  bool operator<(const Option& other) const {
    return cost > other.cost;
  }
};

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int K) {
    graph = ConstructGraph(n);
    max_stops = K;
    MakeConnections(flights);
    // PrintGraph();
    int best = Cheapest(graph[src], graph[dest]);
    if (best == INF) {
      return -1;
    }
    return best;
  }
private:
  vector<Node*> graph;
  int max_stops;
  const int INF = 1e4 + 5;

  void PrintGraph() {
    for (auto node : graph) {
      node->Print();
    }
  }

  vector<Node*> ConstructGraph(int nodes) {
    vector<Node*> graph;
    for (int i = 0; i < nodes; i++) {
      graph.push_back(new Node(i));
    }
    return graph;
  }

  void MakeConnections(const vector<vector<int>>& flights) {
    for (auto flight : flights) {
      int node_from = flight[0];
      int node_to = flight[1];
      int weight = flight[2];
      graph[node_from]->neighs.push_back({node_to, weight});
    }
  }

  int Cheapest(Node* from, Node* to) {
    priority_queue<Option> q;
    q.push({from, 0, 0});
    while (!q.empty()) {
      Option option = q.top();
      q.pop();
      if (option.node->val == to->val) {
        return option.cost;
      }
      if (option.curr_stops > max_stops) {
        continue;
      }
      for (auto neigh : option.node->neighs) {
        q.push({ graph[neigh.to], option.curr_stops + 1, option.cost + neigh.weight });
      }
    }
    return INF;
  }
};

/*

   0 -(1)-> 1
   |        |
  (5)       |
   |        |
   2 <--(1)-|     
   |
  (1)
   |
   3 

*/

struct Test {
  int n;
  vector<vector<int>> flights;
  int src, dest, k;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    { 3, {{0,1,100},{1,2,100},{0,2,500}}, 0, 2, 1, 200 },
    { 3, {{0,1,100},{1,2,100},{0,2,500}}, 0, 2, 0, 500 },
    { 3, {}, 0, 2, 1, -1 },
    { 4, {{0,1,1},{0,2,5},{1,2,1},{2,3,1}}, 0, 3, 1, 6 },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.findCheapestPrice(test.n, test.flights, test.src, test.dest, test.k);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}