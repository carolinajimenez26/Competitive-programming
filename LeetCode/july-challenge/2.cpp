#include <iostream>
#include <vector>
#include <queue>
#include <string> 
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
  vector<int> ProcessLevel(queue<TreeNode*>& q) {
    queue<TreeNode*> q_next_level;
    vector<int> curr_level;
    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();
      curr_level.push_back(node->val);
      if (node->left != nullptr) q_next_level.push(node->left);
      if (node->right != nullptr) q_next_level.push(node->right);
    }
    q = q_next_level;
    return curr_level;
  }

  void Reverse(vector<vector<int>>& v) {
    int size = v.size() / 2;
    for (int i = 0, j = v.size() - 1; i < size; i++, j--) {
      vector<int> tmp = v[i];
      v[i] = v[j];
      v[j] = tmp;
    }
  }

public:
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    if (root == nullptr) return {};
    queue<TreeNode*> q;
    vector<vector<int>> ans;
    q.push(root);
    while (!q.empty()) {
      vector<int> curr_level = ProcessLevel(q);
      ans.push_back(curr_level);
    }
    Reverse(ans);
    return ans;
  }
};

TreeNode* Build(vector<string>& tree) {
  if (tree.empty()) return nullptr;
  vector<TreeNode*> nodes;
  for (int i = 0; i < tree.size(); i++) {
    if (tree[i] == "null") {
      nodes.push_back(nullptr);
    } else {
      int val = stoi(tree[i]);
      TreeNode* node = new TreeNode(val);
      nodes.push_back(node);
    }
  }

  for (int i = 0; i < tree.size(); i++) {
    if (2 * i + 1 < tree.size()) nodes[i]->left = nodes[2 * i + 1];
    if (2 * i + 1 < tree.size()) nodes[i]->right = nodes[2 * i + 2];
  }
  return nodes[0];
}

void print2D(TreeNode *root, int space = 0, int COUNT = 10) {
  // Base case
  if (root == nullptr) return;
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

struct Test {
  vector<string> tree;
  vector<vector<int>> ans;
};

void Print(vector<int>& vi) {
  cout << "[";
  for (auto i : vi) {
    cout << i << ", ";
  }
  cout << " ]";
}

void Print(vector<vector<int>>& vvi) {
  cout << "[ ";
  for (auto vi : vvi) {
    Print(vi);
    cout << ", ";
  }
  cout << " ]" << endl;
}

int main(void) {
  vector<Test> tests = {
    {
      {"3","9","20","null","null","15","7"},
      {
        {15,7},
        {9,20},
        {3}
      }
    },
    {
      {"3","9","20","2","3","15","7"},
      {
        {2,3,15,7},
        {9,20},
        {3}
      }
    },
    {
      {"3"},
      {
        {3}
      }
    },
    {
      {},
      {}
    },
    {
      {"3","9","null","1","2"},
      {
        {1,2},
        {9},
        {3}
      }
    },
  };
  int tc = 0;
  bool succeed = true;
  Solution sol;
  for (auto test : tests) {
    TreeNode* root = Build(test.tree);
    // print2D(root);
    // Print(test.ans);
    vector<vector<int>> out = sol.levelOrderBottom(root);
    if (out != test.ans) {
      cout << "Failed on test #" << tc << ". Found: "; 
      Print(out); 
      cout << ", expected ";
      Print(test.ans);
      cout << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}