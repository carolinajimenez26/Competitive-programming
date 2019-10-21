#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

#define dbg(x) cout << #x << ": " << x << endl

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    set<int> used;
    set<int> in_process;
    vector<int> pre;
    vector<int> post;
    unordered_map<int, int> pre_indexes;
    unordered_map<int, int> post_indexes;
public:
    TreeNode* CreateNode(int pre_idx, int post_idx) {
        TreeNode* curr = new TreeNode(pre[pre_idx]);
        in_process.insert(curr->val);

        int left_node_val = -1;
        int right_node_val = -1;

        if (pre_idx + 1 < pre.size() && in_process.find(pre[pre_idx + 1]) == in_process.end() &&
            used.find(pre[pre_idx + 1]) == used.end()) {
            left_node_val = pre[pre_idx + 1];
            in_process.insert(left_node_val);
        }

        if (post_idx - 1 >= 0 && in_process.find(post[post_idx - 1]) == in_process.end() &&
            used.find(post[post_idx - 1]) == used.end()) {
            right_node_val = post[post_idx - 1];
            in_process.insert(right_node_val);
        }

        curr->left = left_node_val == -1 ? nullptr : CreateNode(pre_idx + 1, post_indexes[left_node_val]);
        curr->right = right_node_val == -1 ? nullptr : CreateNode(pre_indexes[right_node_val], post_idx - 1);
        
        in_process.erase(curr->val);
        used.insert(curr->val);
        return curr;
    }

    void Initialize(unordered_map<int, int>& indexes, const vector<int>& info) {
        for (int i = 0; i < info.size(); i++) {
            indexes[info[i]] = i;
        }
    }

    TreeNode* constructFromPrePost(vector<int>& pre_, vector<int>& post_) {
        if (pre_.empty() || post_.empty()) return nullptr;
        pre = pre_;
        post = post_;
        Initialize(pre_indexes, pre_);
        Initialize(post_indexes, post_);
        return CreateNode(0, post_.size() - 1);
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
    vector<int> pre = {1,2,4,5,3,6,7};
    vector<int> pos = {4,5,2,6,7,3,1};
    Solution sol;
    TreeNode* out = sol.constructFromPrePost(pre, pos);
    print2D(out, 0, 10);
    return 0;
}