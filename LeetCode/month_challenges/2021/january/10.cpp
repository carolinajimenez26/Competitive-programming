#include <iostream>
#include <vector>
using namespace std;

using int64 = long long int;
class SegmentTree {
public:
  SegmentTree(const int size) {
    A.assign(size, 0);
    n = size;
    st.assign(4 * n, 0);
  }

  int64 SumInRange(int i, int j) {
    return SumInRange(1, 0, n - 1, i, j);
  }

  void Increase(const int pos) {
    A[pos] += 1;
    Change(1, 0, n - 1, pos);
  }
private:
  vector<int64> st, A;
  int n;

  int Left(int p) { 
    return p * 2; 
  }

  int Right(int p) { 
    return (p * 2) + 1; 
  }

  // [i, j] is a fixed interval.
  // [L, R] is changing according to the node.
  int64 SumInRange(int node_idx, int L, int R, int i, int j) { // O(log n)
    // interval [i,j] is outside interval [L,R] 
    // that is either: 
    //      - [L,R][i, j] i > R
    //      - [i, j] [L, R] j < L
    if (!InRange(L, i, j) && !InRange(R, i, j)) return 0;

    // [L, R] is fully contained in [i, j]:
    // that is: [i, [L, R], j]
    if (InRange(L, i, j) && InRange(R, i, j)) return st[node_idx];


    // [L, R] is partially contained, try to split.
    int mid = (L + R) / 2;
    int64 sum_left = SumInRange(Left(node_idx), L, mid, i, j);
    int64 sum_right = SumInRange(Right(node_idx), mid + 1, R, i, j);

    return sum_left + sum_right;
  }

  bool InRange(int idx, int L, int R) {
    return idx >= L && idx <= R;
  }

  void Change(int node_idx, int L, int R, const int element_pos) {
    if (L == R && L == element_pos) {
      st[node_idx] = A[element_pos];
      return;
    }
    if (!InRange(element_pos, L, R)) {
      return;
    }
    Change(Left(node_idx), L, (L + R) / 2, element_pos);
    Change(Right(node_idx), (L + R) / 2 + 1, R, element_pos);
    int64 sum_left = st[Left(node_idx)]; 
    int64 sum_right = st[Right(node_idx)];
    st[node_idx] = sum_left + sum_right;
  }
};

class Solution {
public:
  int createSortedArray(vector<int>& instructions) {
    const int64 mod = 1e9 + 7;
    const int MAX = *max_element(instructions.begin(), instructions.end()) + 3;
    SegmentTree st(MAX);
    int64 cost = 0;
    for (int i = 0; i < instructions.size(); i++) {
      int elem = instructions[i];
      st.Increase(elem);
      int64 left = st.SumInRange(0, elem - 1);
      int64 right = st.SumInRange(elem + 1, MAX - 1);
      cost += min(left, right);
      cost %= mod;
    }
    return cost;
  }
};

struct Test {
  vector<int> instructions;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    { {1,5,6,2}, 1 },
    { {1,2,3,6,5,4}, 3 },
    { {1,3,3,3,2,4,2,1,2}, 4 },
    { {1,2,3,4,5}, 0 },
    { {5,4,3,2,1}, 0 },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.createSortedArray(test.instructions);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out 
           << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}