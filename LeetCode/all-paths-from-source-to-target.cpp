#include <iostream>
#include <vector>

using namespace std;
#define dbg(x) cout << #x << ": " << x << endl

void print(vector<vector<int>> v) {
  cout << "[ ";
  for (auto& vi : v) {
    cout << "[";
    for (auto& i : vi) cout << i << ",";
    cout << "], ";
  }
  cout << " ]" <<  endl;
}

template <class T>
void print(T v) {
  for (auto i : v) cout << i << " ";
  cout << endl;
}

void DFS(vector<vector<int>>& graph, int node, vector<bool> &visited, int target,
         vector<int> &currentPath, vector<vector<int>>& pathsToTarget) {
  // dbg(node);
  visited[node] = true;
  // print(visited);
  currentPath.push_back(node);
  // print(currentPath);
  if (currentPath[currentPath.size() - 1] == target)
    pathsToTarget.push_back(currentPath);

  for (int i = 0; i < graph[node].size(); i++) { // for each neighbor of node
    int neigh = graph[node][i];
    DFS(graph, neigh, visited, target, currentPath, pathsToTarget);
    currentPath.pop_back();
    visited[neigh] = false;
  }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
  int target = graph.size() - 1;
  vector<vector<int>> result;
  vector<bool> visited(graph.size(), false);
  vector<int> currentPath;
  DFS(graph, 0, visited, target, currentPath, result);
  return result;
}

int main(void) {
  vector<vector<vector<int>>> inputs = {
    { {1,2}, {3}, {3}, {} },
    { {1,2}, {}, {3}, {} },
    { {1,2}, {}, {}, {} }
  };
  vector<vector<vector<int>>> expectedOutput = {
    { {0,1,3},{0,2,3} },
    { {0,2,3} },
    { }
  };
  bool succeed = true;

  for (int i = 0; i < inputs.size(); i++) {
    vector<vector<int>> output = allPathsSourceTarget(inputs[i]);
    if (expectedOutput[i] != output) {
      cout << "Expected ";
      print(expectedOutput[i]);
      cout << "Received ";
      print(output);
      succeed = false;
    }
  }

  if (succeed) cout << "Good Job" << endl;
  else cout << "Keep trying" << endl;
  return 0;
}
