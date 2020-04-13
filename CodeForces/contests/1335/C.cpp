#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#define dbg(x) cout << #x << ": " << x << endl

using namespace std;

int MaxSizeTeams(const vector<int>& A) {
  if (A.size() < 2) {
    return 0;
  }
  int result = 0;
  unordered_map<int, int> freqs;
  int max_count_A = 0;
  int max_element = -1;
  for (auto e : A) {
    freqs[e]++;
    if (freqs[e] > max_count_A) {
      max_count_A = freqs[e];
      max_element = e;
    }
  }
  // dbg(max_count_A); dbg(max_element);
  int max_count_B = 0;
  unordered_set<int> B;
  for (auto e : A) {
    if (max_count_B == max_count_A) {
      break;
    }
    if (e != max_element && B.count(e) == 0) {
      max_count_B++;
      B.insert(e);
    }
  }
  if (max_count_A - max_count_B > 1) {
    max_count_B++;
  }
  return max_count_B;
}

int main(void) {
  int tc, n;
  cin >> tc;
  while (tc--) {
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
      cin >> A[i];
    }
    cout << MaxSizeTeams(A) << endl;
  }
  return 0;
}