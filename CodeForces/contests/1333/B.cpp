#include <iostream>
#include <vector>
#define MAX 1e5 + 10
#define dbg(x) cout << #x << ": " << x << endl

using namespace std;

bool CanBecomeEqual(const vector<int>& A, const vector<int>& B, int size) {
  vector<int> seen(3, 0); // pos 0 for 0, pos 1 for 1 and pos 2 for -1
  for (int i = 0; i < size; i++) {
    if (A[i] == B[i]) {
      seen[A[i] == -1 ? 2 : A[i]] = 1;
      continue;
    }
    long long int x = B[i] - A[i];
    if (x < 0 && seen[2] == 0) {
      return false; // Can't use the -1 yet
    }
    if (x == 0 && seen[0] == 0) {
      return false; // Can't use the 0 yet
    }
    if (x > 0 && seen[1] == 0) {
      return false; // Can't use the 1 yet
    }
    seen[A[i] == -1 ? 2 : A[i]] = 1;
  }
  return true;
}

int main(void) {
  int tc, n;
  vector<int> A(MAX), B(MAX);
  cin >> tc;
  while (tc--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> B[i];
    }
    cout << (CanBecomeEqual(A, B, n) ? "YES" : "NO") << endl;
  }
  return 0;
}