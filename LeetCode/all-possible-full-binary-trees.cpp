#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> allPossibleFBT(int len) { // [0:len-1] [0, 1, 2, 3 ]
  vector<TreeNode*> ans;
  if (len == 1) {
      ans.push_back(new TreeNode(0));
      return ans;
  }
  for (int root = 1; root < len - 1; root++) {
    vector<TreeNode*> left = allPossibleFBT(root);
    vector<TreeNode*> right = allPossibleFBT(len - root - 1);
    for (auto* t1 : left) {
      for (auto* t2 : right) {
        auto* tRoot = new TreeNode(0);
        tRoot->left = t1;
        tRoot->right = t2;
        ans.push_back(tRoot);
      }
    }
  }
  return ans;
}

int main(void) {
  int input = 7;
  // expectedOutput: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
  vector<TreeNode*> output = allPossibleFBT(input);
  return 0;
}
