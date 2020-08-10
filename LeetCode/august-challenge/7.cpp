#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Point {
  int x, y;
};

struct Element {
  int val;
  Point point;

  bool operator<(const Element& other) const {
    if (point.y == other.point.y) return val < other.val;
    return point.y > other.point.y;
  }
};

class Solution {
private:
  map<int,set<Element>> x_positions_nodes;

  void VerticalTraversal(TreeNode* node, Point point) {
    if (node == nullptr) return;
    int x = point.x, y = point.y;
    x_positions_nodes[x].insert({node->val, point});
    VerticalTraversal(node->left, {x - 1, y - 1});
    VerticalTraversal(node->right, {x + 1, y - 1});
  }
public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    VerticalTraversal(root, {0, 0});
    vector<vector<int>> ans(x_positions_nodes.size());
    int i = 0;
    for (auto [x, elements] : x_positions_nodes) {
      for (auto elem : elements) {
        ans[i].push_back(elem.val);
      }
      i++;
    }
    return ans;
  }
};
/*
Test cases:

[0,5,1,9,null,2,null,null,null,null,3,4,8,6,null,null,null,7] --> [[9,7],[5,6],[0,2,4],[1,3],[8]]
[0,8,1,null,null,3,2,null,4,5,null,null,7,6] --> [[8],[0,3,6],[1,4,5],[2,7]]
[0,2,1,3,null,null,null,4,5,null,7,6,null,10,8,11,9] --> [[4,10,11],[3,6,7],[2,5,8,9],[0],[1]]
*/

int main(void) {
  return 0;
}
