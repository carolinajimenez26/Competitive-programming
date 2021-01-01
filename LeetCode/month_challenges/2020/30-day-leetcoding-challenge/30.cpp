#include <iostream>
#include <vector>
#define dbg(x) cout << #x << ": " << x << endl
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
  bool TraverseAndCompare(TreeNode* root, const vector<int>& v, int idx) {
    // dbg(idx);
    if (root == nullptr || idx >= v.size()) return false;
    if (v[idx] != root->val) return false;
    if (idx == v.size() - 1) {
      return root->left == nullptr && root->right == nullptr;
    }
    return TraverseAndCompare(root->left, v, idx + 1) ||
           TraverseAndCompare(root->right, v, idx + 1);
  }

public:
  bool isValidSequence(TreeNode* root, vector<int>& arr) {
    return TraverseAndCompare(root, arr, 0);
  }
};

int main(void) {
  TreeNode* root = new TreeNode(8);
  root->left = new TreeNode(3);

  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(1);

  root->left->left->left = new TreeNode(5);
  root->left->left->right = new TreeNode(4);

  vector<int> v = {8};

  Solution sol;
  cout << sol.isValidSequence(root, v) << endl;
  return 0;
}