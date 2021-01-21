#include <bits/stdc++.h>
using namespace std;
#define COUNT 10

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

int main(void) {
  int arr[] = {18, 17, 13, 19, 15, 11, 20};
  vector<int> A(arr, arr + 7);
  SegmentTree st(A);
  st.Print();
  cout << "RMQ(1,3) = " << st.MinInRange(1,3) << endl;
  cout << "RMQ(4,6) = " << st.MinInRange(4,6) << endl;
  arr[5] = 99;
  st.change(5, 99);
  // st.Print();
  cout << "RMQ(4,6) = " << st.MinInRange(4,6) << endl;
  st.change(2, 1);
  // st.Print();
  cout << "RMQ(0,6) = " << st.MinInRange(0,6) << endl;
  return 0;
}
