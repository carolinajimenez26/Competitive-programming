#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
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

struct Data {
  vector<int> inorder, postorder;
  vector<bool> used;
  int used_idx;

  Data(const vector<int>& inorder_, const vector<int>& postorder_) {
    inorder = inorder_;
    postorder = postorder_;
    used.resize(postorder.size(), false);
  }

  int GetNextAvailable() {
    while (true) {
      if (used_idx < 0) {
        return -1;
      }
      if (used[used_idx] == false) {
        return used_idx;
      }
      used_idx--;
    }
  }
};

class Solution {
private:
  TreeNode* buildTree(Data& data, int from, int to) { // from and to are for inorder vector
    if (from > to) {
      return nullptr;
    }
    if (from == to) {
      int idx = FindElemPos(data.postorder, data.inorder[from]);
      assert(idx != -1);
      data.used[idx] = true;
      return new TreeNode(data.inorder[from]);
    }
    int next_available = data.GetNextAvailable();
    assert(next_available != -1);

    int root_val = data.postorder[next_available];
    TreeNode* root = new TreeNode(root_val);
    data.used[next_available] = true;
    int pos = FindElemPos(data.inorder, root_val);

    root->right = buildTree(data, pos + 1, to);
    root->left = buildTree(data, from, pos - 1);
    return root;
  }

  int FindElemPos(const vector<int>& v, int val) {
    for (int i = 0; i < v.size(); i++) {
      if (v[i] == val) return i;
    }
    return -1;
  }

public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.empty() || postorder.empty()) return nullptr;
    Data data(inorder, postorder);
    TreeNode* root = new TreeNode(data.postorder.back());
    data.used_idx = data.used.size() - 1;
    data.used[data.used_idx] = true;
    int pos = FindElemPos(data.inorder, root->val);
    assert(pos != -1);
    root->right = buildTree(data, pos + 1, data.postorder.size() - 1);
    root->left = buildTree(data, 0, pos - 1);
    return root;
  }
};

struct Test {
  vector<int> inorder, postorder;
  vector<string> ans;
};

void Print(const vector<string>& v) {
  for (auto s : v) cout << s << ", ";
  cout << endl;
}

vector<string> Convert(TreeNode* root) {
  vector<string> ans;
  if (root == nullptr) return ans;
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode* curr = q.front();
    q.pop();
    if (curr == nullptr) {
      ans.push_back("null");
      continue;
    }
    ans.push_back(to_string(curr->val));
    q.push(curr->left);
    q.push(curr->right);
  }
  while (ans.back() == "null") {
    ans.pop_back();
  }
  return ans;
}

void TestConvert() {
  TreeNode* root = new TreeNode(1);
  vector<string> expected = {"1"};
  Print(Convert(root));
  if (Convert(root) != expected) {
    cout << "Failed" << endl;
    assert(false);
  }
  root->left = new TreeNode(2);
  Print(Convert(root));
  expected = {"1", "2"};
  if (Convert(root) != expected) {
    cout << "Failed" << endl;
    assert(false);
  }
  root->right = new TreeNode(3);
  Print(Convert(root));
  expected = {"1", "2", "3"};
  if (Convert(root) != expected) {
    cout << "Failed" << endl;
    assert(false);
  }
  root->left->right = new TreeNode(4);
  Print(Convert(root));
  expected = {"1", "2", "3", "null", "4"};
  if (Convert(root) != expected) {
    cout << "Failed" << endl;
    assert(false);
  }
  root->right->left = new TreeNode(5);
  Print(Convert(root));
  expected = {"1", "2", "3", "null", "4", "5"};
  if (Convert(root) != expected) {
    cout << "Failed" << endl;
    assert(false);
  }
  root->right->left->right = new TreeNode(6);
  Print(Convert(root));
  expected = {"1", "2", "3", "null", "4", "5", "null", "null", "null", "null", "6"};
  if (Convert(root) != expected) {
    cout << "Failed" << endl;
    assert(false);
  }
  cout << "Passed!" << endl;
}

int main (void) {
  // TestConvert();
  vector<Test> tests = {
    {
      {9,3,15,20,7}, {9,15,7,20,3}, {"3", "9", "20", "null", "null", "15", "7"}
    },
    {
      {1,9,3,15,20,7}, {1, 9,15,7,20,3}, {"3", "9", "20", "1", "null", "15", "7"}
    },
    {
      {}, {}, {}
    },
    {
      {1}, {1}, {"1"}
    },
    {
      {1,3}, {1,3}, {"3", "1"}
    },
    {
      {1,2,3,4}, {1,2,4,3}, {"3", "2", "4", "1"}
    },
  };
  Solution sol;
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    TreeNode* out = sol.buildTree(test.inorder, test.postorder);
    vector<string> converted = Convert(out);
    if (converted != test.ans) {
      cout << "Failed on test #" << tc << ". Found: " << endl;
      Print(converted);
      cout << "Expected: " << endl;
      Print(test.ans);
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}