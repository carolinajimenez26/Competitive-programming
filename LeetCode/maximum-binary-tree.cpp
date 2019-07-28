#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <assert.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print(vector<int> v) {
  for (auto& e : v) cout << e << " ";
  cout << endl;
}

int getMaxNumberIndex(vector<int>& nums, int leftIndex, int rightIndex) {
  int maxNumberIndex = -1, maxNumber = numeric_limits<int>::min();
  for (int i = leftIndex; i <= rightIndex; i++) {
    if (nums[i] > maxNumber) {
      maxNumber = nums[i];
      maxNumberIndex = i;
    }
  }
  return maxNumberIndex;
}

TreeNode* constructMaximumBinaryTreeHandler(vector<int>& nums, int leftIndex, int rightIndex) {
  if (leftIndex > rightIndex) return nullptr;
  int maxIndex = getMaxNumberIndex(nums, leftIndex, rightIndex);
  TreeNode* node = new TreeNode(nums[maxIndex]);
  TreeNode* leftNode = constructMaximumBinaryTreeHandler(nums, leftIndex, maxIndex - 1);
  TreeNode* rightNode = constructMaximumBinaryTreeHandler(nums, maxIndex + 1, rightIndex);

  node->left = leftNode;
  node->right = rightNode;

  return node;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
  return constructMaximumBinaryTreeHandler(nums, 0, nums.size() - 1);
}

int main(void) {
  vector<int> input = {3,2,1,6,0,5};
  TreeNode* root = constructMaximumBinaryTree(input);
  delete root;
  return 0;
}
