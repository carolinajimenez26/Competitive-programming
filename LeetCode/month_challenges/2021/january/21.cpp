#include <iostream>
#include <vector>
using namespace std;

void Print(const vector<int>& v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

class SegmentTree {
public:
  SegmentTree(const vector<int>& v) {
    A = v;
    n = v.size();
    st.assign(4 * n, 0);
    Build(1, 0, n - 1);
  }

  void Build(int node_idx, int L, int R) {
    if (L == R) {
      st[node_idx] = L;
      return;
    }
    Build(Left(node_idx), L, (L + R) / 2);
    Build(Right(node_idx), (L + R) / 2 + 1, R);
    int min_left = st[Left(node_idx)];
    int min_right = st[Right(node_idx)];
    int min_pos = (A[min_left] <= A[min_right]) ? min_left : min_right;
    st[node_idx] = min_pos;
  }

  int MinInRange(int i, int j) {
    return MinInRange(1, 0, n - 1, i, j);
  }

  void Change(const int pos, int num) {
    A[pos] = num;
    Change(1, 0, n - 1, pos);
  }

  void Print() {
    Print(1, 0, n - 1, 0);
  }
private:
  vector<int> st, A;
  int n;
  const int COUNT = 10;

  int Left(int p) { 
    return p * 2; 
  }

  int Right(int p) { 
    return (p * 2) + 1; 
  }

  // [i, j] is a fixed interval.
  // [L, R] is changing according to the node.
  int MinInRange(int node_idx, int L, int R, int i, int j) { // O(log n)
    // interval [i,j] is outside interval [L,R] 
    // that is either: 
    //      - [L,R][i, j] i > R
    //      - [i, j][L, R] j < L
    if (i > R || j < L) return -1;

    // [L, R] is fully contained in [i, j]:
    // that is: [i, [L, R], j]
    if (InRange(L, i, j) && InRange(R, i, j)) return st[node_idx];

    // [L, R] is partially contained, try to split.
    int mid = (L + R) / 2;
    int min_left = MinInRange(Left(node_idx), L, mid, i, j);
    int min_right = MinInRange(Right(node_idx), mid + 1, R, i, j);
    if (min_left == -1) {
      return min_right;
    }
    if (min_right == -1) {
      return min_left;
    }
    int min_pos = (A[min_left] <= A[min_right]) ? min_left : min_right;
    return min_pos;
  }

  bool InRange(int idx, int L, int R) {
    return idx >= L && idx <= R;
  }

  void Change(int node_idx, int L, int R, const int element_pos) {
    if (L == R && L == element_pos) {
      st[node_idx] = element_pos;
      return;
    }
    if (!InRange(element_pos, L, R)) {
      return;
    }
    Change(Left(node_idx), L, (L + R) / 2, element_pos);
    Change(Right(node_idx), (L + R) / 2 + 1, R, element_pos);
    int min_left = st[Left(node_idx)]; 
    int min_right = st[Right(node_idx)];
    int min_pos = (A[min_left] <= A[min_right]) ? min_left : min_right;
    st[node_idx] = min_pos;
  }

  void Print(int node_idx, int L, int R, int space) {
    space += COUNT;
    if (L == R) {
      for (int i = COUNT; i < space; i++) cout << " ";
      cout << st[node_idx] << endl;
      return;
    }
    Print(Left(node_idx), L, (L + R) / 2, space);
    cout << endl;
    for (int i = COUNT; i < space; i++) cout << " ";
    cout << st[node_idx] << endl;
    Print(Right(node_idx), (L + R) / 2 + 1, R, space);
  }
};

class Solution {
public:
  vector<int> mostCompetitive(vector<int>& nums_, int k) {
    nums = nums_;
    SegmentTree st(nums);
    // Print(nums);
    // st.Print();
    CalculateMostCompetitive(0, k, st);
    return ans;
  }
private:
  vector<int> ans;
  vector<int> nums;

  void CalculateMostCompetitive(int from, int k, SegmentTree& min_query) {
    if (k == 0) {
      return;
    }
    int to = nums.size() - k;
    int min_pos = min_query.MinInRange(from, to);
    ans.push_back(nums[min_pos]);
    CalculateMostCompetitive(min_pos + 1, k - 1, min_query);
  }
};

/*
 0 1 2 3 4 5 6
[4,5,3,4,9,2,6], k =3

solve(0, k = 3) ==>

from = left = 0
to = 7 - 3 = 4
min_pos = GetMin(from, to) = 2
ans = [3]

solve(left = 3, k = 2) => 

from = left = 3
to = 7 - 2 = 5
min_pos = GetMin(from, to) = 5
ans = [3,2]

solve(left = 6, k = 1)

from = left = 6
to = 7 - 1 = 6
min_pos = GetMin(from, to) = 6
ans = [3,2,6]

solve(left = 7, k = 0)
return

*/

struct Test {
  vector<int> nums;
  int k;
  vector<int> expected;
};

int main(void) {
  vector<Test> tests = {
    { {4,5,3,4,9,2,6}, 3, {3,2,6} },
    { {3,5,2,6}, 2, {2,6} },
    { {2,4,3,3,5,4,9,6}, 4, {2,3,3,4} },
    { {3,5,2,6}, 4, {3,5,2,6} },
    { {3,5,2,6}, 3, {3,2,6} },
    { {9,8,7,6,5,4,3,2,1}, 3, {3,2,1} },
    { {1,2,3,4,5,6,7,8,9}, 3, {1,2,3} },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    vector<int> out = sol.mostCompetitive(test.nums, test.k);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << endl;
      Print(out);
      Print(test.expected);
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}