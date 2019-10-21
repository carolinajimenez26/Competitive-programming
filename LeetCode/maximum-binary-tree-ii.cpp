#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
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

    TreeNode* constructMaximumBinaryTree(vector<int>& nums, int leftIndex, int rightIndex) {
        if (leftIndex > rightIndex) return nullptr;
        int maxIndex = getMaxNumberIndex(nums, leftIndex, rightIndex);
        TreeNode* node = new TreeNode(nums[maxIndex]);
        TreeNode* leftNode = constructMaximumBinaryTree(nums, leftIndex, maxIndex - 1);
        TreeNode* rightNode = constructMaximumBinaryTree(nums, maxIndex + 1, rightIndex);

        node->left = leftNode;
        node->right = rightNode;

        return node;
    }

    void Reconstruct(TreeNode* root, vector<int>& result) {
        if (root == nullptr) return;
        Reconstruct(root->left, result);
        result.push_back(root->val); 
        Reconstruct(root->right, result);
    }

    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        vector<int> original;
        Reconstruct(root, original);
        original.push_back(val);
        return constructMaximumBinaryTree(original, 0, original.size() - 1);
    }
};

void print2D(TreeNode *root, int space, int COUNT) {
  // Base case
  if (root == NULL) return;
  // Increase distance between levels
  space += COUNT;

  // Process right child
  print2D(root->right, space, COUNT);

  cout << endl;
  for (int i = COUNT; i < space; i++) cout << " ";
  cout << root->val << endl;

  // Process left child
  print2D(root->left, space, COUNT);
}

int main(void) {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    print2D(root, 0, 10);
    cout << endl << endl;

    Solution sol;

    TreeNode* out = sol.insertIntoMaxTree(root, 5);
    print2D(out, 0, 10);

    return 0;
}