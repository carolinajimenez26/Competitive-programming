#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
public:
  DisjointSet(int size) {
    parent.resize(size);
    sizes.assign(size, 1);
    for (int i = 0; i < size; i++) {
      parent[i] = i;
    }
  }

  int FindSet(int x) {
    if (parent[x] == x) {
      return x;
    }
    parent[x] = FindSet(parent[x]);
    return parent[x];
  }

  int Union(int a, int b) {
    int set_a = FindSet(a);
    int set_b = FindSet(b);
    if (set_a == set_b) {
      return sizes[set_a];
    }
    parent[set_b] = set_a;
    sizes[set_a] += sizes[set_b];
    sizes[set_b] = 1;
    return sizes[set_a];
  }

  int GetSize(int x) {
    return sizes[x];
  }
private:
  vector<int> parent;
  vector<int> sizes;
};

void CreateSets(const vector<vector<int>>& cities, DisjointSet& ds ) {
  for (auto city : cities) {
    int u = city[0] - 1;
    int v = city[1] - 1;
    ds.Union(u, v);
  }
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
  DisjointSet ds(n);
  CreateSets(cities, ds);
  long result = 0;
  for (int node = 0; node < n; node++) {
    if (ds.FindSet(node) != node) {
      continue;
    }
    int component_size = ds.GetSize(node);
    result += (c_lib + min(c_lib, c_road) * (component_size - 1));
  }
  return result;
}

struct Test {
  int nodes, connections, cost_lib, cost_route;
  vector<vector<int>> cities;
  long expected;
};

int main(void) {
  vector<Test> tests = {
    { 6, 4, 2, 3, {{1,2},{1,3},{4,5},{4,6}}, 12 },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    long out = roadsAndLibraries(test.nodes, test.cost_lib, test.cost_route, test.cities);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}