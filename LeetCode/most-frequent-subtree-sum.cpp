#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getSums(TreeNode* node, map<int, int>& frec) {
    if (node == nullptr) return 0;
    int count = node->val;
    count += getSums(node->left, frec);
    count += getSums(node->right, frec);
    if (frec.count(count)) frec[count] += 1;
    else frec[count] = 1;
    return count;
}

vector<int> findFrequentTreeSum(TreeNode* root) {
    map<int, int> frec;
    vector<int> result;
    getSums(root, frec);
    int most_frec = 0;
    for (auto e : frec) {
        if (e.second > most_frec) most_frec = e.second;
    }
    for (auto e : frec) {
        if (e.second == most_frec) result.push_back(e.first);
    }
    return result;
}

int main(void) {
    return 0;
}