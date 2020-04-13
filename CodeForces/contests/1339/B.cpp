#include <iostream>
#include <vector>
#include <algorithm>
// #define MAX 1e5 + 10

using namespace std;

void print(const vector<int>& v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i];
    if (i != v.size() - 1) {
      cout << " ";
    }
  }
  cout << endl;
}

int main(void) {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
      cin >> A[i];
    }
    sort(A.begin(), A.end());
    vector<int> result(A.size());
    int left = 0, right = A.size() - 1;
    int i = right;
    while (left < right) {
      result[i] = A[right];
      result[i - 1] = A[left];
      i -= 2;
      left++;
      right--;
    }
    if (left == right) {
      result[i] = A[left];
    }
    print(result);
  }
  return 0;
}