#include <bits/stdc++.h>
using namespace std;

void print(vector<int> v) {
  for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << endl;
}

void solver(vector<int> &left, vector<int> &right, int l, int r) {
  left[ right[r] ] = left[l];
  right[ left[l] ] = right[r];

  // print(left);
  // print(right);

  left[l] == 0 ? cout << "* " : cout << left[l] << " ";
  right[r] == 0 ? cout << "*" << endl : cout << right[r] << endl;
}

int main(void) {
  int S, B, L, R;
  while (true) {
    cin >> S >> B;
    if (S == 0 and B == 0) break;
    vector<int> left, right;
    right.push_back(-1);
    left.push_back(-1);
    for (int i = 1; i <= S; i++) {
      right.push_back(i + 1);
      left.push_back(i - 1);
    }
    right[S] = 0;
    // print(left);
    // print(right);
    for (int i = 0; i < B; i++) {
      cin >> L >> R;
      solver(left, right, L, R);
    }
    cout << "-" << endl;
  }
  return 0;
}
