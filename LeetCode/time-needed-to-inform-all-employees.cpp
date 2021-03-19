#include <iostream>
#include <vector>
#include <limits>
using namespace std;

struct Node {
  int id;
  int inform_time;
  vector<Node*> neighbors;

  Node(int id, int inform_time) : id(id), inform_time(inform_time) {}

  void AddNeigh(Node* node) {
    neighbors.push_back(node);
  }

  bool IsLeaf() {
    return neighbors.size() == 0;
  }
};

class Solution {
private:
  vector<Node*> graph;
  const int INF = numeric_limits<int>::max();

  void CreateGraph(int size, const vector<int>& informTime) {
    for (int i = 0; i < size; i++) {
      graph.push_back(new Node(i, informTime[i]));
    }
  }

  void CreateConnections(const vector<int>& manager) {
    for (int employee = 0; employee < manager.size(); employee++) {
      int curr_manager = manager[employee];
      if (curr_manager == -1) {
        continue;
      }
      graph[curr_manager]->AddNeigh(graph[employee]);
    }
  }

  int GetTimeToInformEveryone(Node* node) {
    if (node->IsLeaf()) {
      return 0;
    }
    int max_time = -INF;
    for (auto neigh : node->neighbors) {
      int inform_time_neigh = GetTimeToInformEveryone(neigh);
      max_time = max(max_time, inform_time_neigh);
    }
    return max_time + node->inform_time;
  }

public:
  int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& inform_time) {
    if (n == 1) {
      return 0;
    }
    CreateGraph(n, inform_time);
    CreateConnections(manager);
    Node* root = graph[headID];
    return GetTimeToInformEveryone(root);
  }
};

int main(void) {
  int n = 7; 
  int root = 2;
  vector<int> manager = {2,2,-1,2,2,2,0}; 
  vector<int> inform_time = {5,0,1,0,0,0,5};
  Solution sol;
  cout << sol.numOfMinutes(n, root, manager, inform_time) << endl;
  return 0;
}