#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Position {
  int x, y;
};

struct CartesianNode {
  Position pos;
  int val;

  CartesianNode(Position pos, int val) : pos(pos), val(val) {}

  bool operator<(const CartesianNode& other) const {
    if (pos.x != other.pos.x) {
      return pos.x < other.pos.x;
    }
    if (pos.y != other.pos.y) {
      return pos.y > other.pos.y;
    }
    return val < other.val;
  }
};

class Solution {
public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    set<CartesianNode> ordered;
    DFS(ordered, root, {0,0});
    return SeparateBySameX(ordered);
  }
private:
  vector<vector<int>> SeparateBySameX(const set<CartesianNode>& ordered) {
    vector<vector<int>> ans;
    if (ordered.empty()) {
      return ans;
    }
    auto it = ordered.begin();
    while (it != ordered.end()) {
      int x = (*it).pos.x;
      auto it2 = it;
      vector<int> partial;
      while (it2 != ordered.end() && (*it2).pos.x == x) {
        partial.push_back((*it2).val);
        it2++;
      }
      ans.push_back(partial);
      it = it2;
    }
    return ans;
  }

  void DFS(set<CartesianNode>& ordered, TreeNode* root, Position pos) {
    if (root == nullptr) {
      return;
    }
    ordered.emplace(pos, root->val);
    DFS(ordered, root->left, { pos.x - 1, pos.y - 1 });
    DFS(ordered, root->right, { pos.x + 1, pos.y - 1 });
  }
};

int main(void) {
  return 0;
}