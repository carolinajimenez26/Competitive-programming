#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

struct Element {
  int idx, topic;

  bool operator<(const Element& other) const {
    return topic < other.topic;
  }
};

bool Impossible(const unordered_map<int,vector<int>>& graph, const vector<Element>& elements) {
  for (auto [node, neighs] : graph) {
    set<int> seen;
    for (auto neigh : neighs) {
      seen.insert(elements[neigh - 1].topic);
    }
    int curr = elements[node - 1].topic;
    for (int topic = 1; topic < curr; topic++) {
      if (seen.count(topic) == 0) return true;
    }
    if (seen.count(curr) == 1) return true;
  }

  return false;
}

int main(void) {
  int n, m;
  cin >> n >> m;
  vector<Element> elements(n);
  unordered_map<int,vector<int>> graph;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for (int i = 0; i < n; i++) {
    int topic;
    cin >> topic;
    elements[i] = {i + 1, topic};
  }
  if (Impossible(graph, elements)) {
    cout << -1 << endl;
  } else {
    sort(elements.begin(), elements.end());
    for (int i = 0; i < elements.size(); i++) {
      cout << elements[i].idx;
      if (i != elements.size() - 1) cout << " ";
    }
    cout << endl;
  }
}