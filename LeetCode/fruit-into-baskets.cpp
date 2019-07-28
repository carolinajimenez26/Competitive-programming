#include <iostream>
#include <vector>
#include <string>
#include <set>
#define dbg(x) cout << #x << ": " << x << endl

using namespace std;

void print(set<pair<int, int>> s) {
  for (auto p : s) {
    cout << p.first << ", " << p.second << endl;
  }
  cout << endl;
}

int nextIdx(int x, vector<int>& tree, int start, int end) {
  for (int i = start; i < end; i++) {
    if (tree[i] != x) return i;
  }
  return -1;
}

int moveUntilDiff(int val, vector<int>& tree, int start) {
  for (int i = start; i >= 0; i--) {
    if (tree[i] != val) return i;
  }
  return -1;
}

int totalFruit(vector<int>& tree) {
  set<pair<int, int>> results;
  int i = 0;
  int j = nextIdx(tree[i], tree, 1, tree.size());
  if (j == -1) {
    return tree.size();
  }
  pair<int,int> baskets;
  baskets.first = tree[i];
  baskets.second = tree[j];
  j++;
  while (j < tree.size()) {
    if (tree[j] != baskets.first && tree[j] != baskets.second) {
      results.insert(make_pair(i, j - 1));
      i = moveUntilDiff(tree[j - 1], tree, j - 1);
      if (i == -1) i = j - 1;
      else i++;
      baskets.first = tree[i];
      baskets.second = tree[j];
    }
    j++;
  }
  results.insert(make_pair(i, j - 1));
  int max = -1;
  for (auto p : results) {
    if (p.second - p.first + 1 > max) {
      max = p.second - p.first + 1;
    }
  }
  // print(results);
  return max;
}

int main(void) {
  vector<int> tree = {0,1,2,2};
  cout << totalFruit(tree) << endl;
  return 0;
}
