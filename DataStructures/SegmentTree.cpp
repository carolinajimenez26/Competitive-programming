#include <bits/stdc++.h>
using namespace std;
#define COUNT 10

class SegmentTree {
private:
  vector<int> st, A;
  int n;

  int left (int p) { return p << 1; }
  int right (int p) { return (p << 1) + 1; }

  void build (int p, int L, int R) { // O(n)
    if (L == R) st[p] = L;
    else {
      build(left(p), L, (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R);
      int p1 = st[left(p)], p2 = st[right(p)];
      st[p] = (A[p1] <= A[p2]) ? p1 : p2;
    }
  }

  // Range Minimum Query
  int rmq (int p, int L, int R, int i, int j) { // O(log n)
    if (i > R || j < L) return -1;
    if (L >= i and R <= j) return st[p];

    int p1 = rmq(left(p), L, (L + R) / 2, i, j);
    int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);

    if (p1 == -1) return p2;
    if (p2 == -1) return p1;
    return (A[p1] <= A[p2]) ? p1 : p2;
  }

  void change (int p, int L, int R, int element_pos) {
    if (L == R && L == element_pos) {
      st[p] = L;
      return;
    }
    if (R < element_pos || L > element_pos) return;
    if (R > n || L < 0) return;
    else {
      change(left(p), L, (L + R) / 2, element_pos);
      change(right(p), (L + R) / 2 + 1, R, element_pos);
      int p1 = st[left(p)], p2 = st[right(p)];
      st[p] = (A[p1] <= A[p2]) ? p1 : p2;
    }
  }

  void print (int p, int L, int R, int space) {
    space += COUNT;
    if (L == R) {
      for (int i = COUNT; i < space; i++)
          printf(" ");

      cout << st[p] << endl;
      return;
    }
    else {
      print(left(p), L, (L + R) / 2, space);

      cout << endl;
      for (int i = COUNT; i < space; i++)
          cout << " ";

      cout << st[p] << endl;

      print(right(p), (L + R) / 2 + 1, R, space);
    }
  }

public:

  SegmentTree (const vector<int> &_A) {
    A = _A;
    n = (int)A.size();
    st.assign(4 * n, 0);
    build(1, 0, n - 1);
  }

  int rmq (int i, int j) {
    return rmq(1, 0, n - 1, i, j);
  }

  void change (int element_pos, int element) { // changes an element of the tree
    A[element_pos] = element;
    change(1, 0, n - 1, element_pos);
  }

  void print () {
    print(1, 0, n - 1, 0);
  }
};

int main(void) {
  int arr[] = {18, 17, 13, 19, 15, 11, 20};
  vector<int> A(arr, arr + 7);
  SegmentTree st(A);
  st.print();
  cout << "RMQ(1,3) = " << st.rmq(1,3) << endl;
  cout << "RMQ(4,6) = " << st.rmq(4,6) << endl;
  arr[5] = 99;
  st.change(5, 99);
  // st.print();
  cout << "RMQ(4,6) = " << st.rmq(4,6) << endl;
  st.change(2, 1);
  // st.print();
  cout << "RMQ(0,6) = " << st.rmq(0,6) << endl;
  return 0;
}
