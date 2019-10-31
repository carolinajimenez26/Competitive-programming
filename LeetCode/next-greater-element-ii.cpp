#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Element {
  int val;
  int pos;
};

class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    vector<int> result(nums.size(), -1);
    stack<Element> st;
    for (int i = 0; i < 2 * nums.size(); i++) {
      int j = i % nums.size();
      Element pivot = {nums[j], j};
      while (!st.empty() && pivot.val > st.top().val) {
        Element e = st.top();
        result[e.pos] = pivot.val;
        st.pop();
      }
      st.push(pivot);
    }
    return result;
  }
};

void Print(const vector<int>& v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

int main(void) {
  vector<int> input = {1,2,1,3,2,3,4,5,6,1,4,6,7,2};
  Solution sol;
  vector<int> out = sol.nextGreaterElements(input);
  Print(out);
  return 0;
}