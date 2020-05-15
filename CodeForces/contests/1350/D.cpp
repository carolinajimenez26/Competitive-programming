#include <iostream>
#include <vector>
using namespace std;

int FindIndex(int target, const vector<int>& v) {
  for (int i = 0; i < v.size(); i++) {
    if (v[i] == target) return i;
  }
  return -1;
}

inline bool IsValid(int pos, int size) {
  return pos >= 0 && pos < size;
}

bool HasElementGreaterEqual(int left, int right, int target,
    const vector<int>& v) {
  int sum = 0;
  for (int i = left; i <= right; i++) {
    if (IsValid(i, v.size()) && v[i] >= target) sum++;
  }
  return sum > 1;
}

bool CanConvertAllTo(int target, const vector<int>& v) {
  int target_idx = FindIndex(target, v);
  if (target_idx == -1) return false;
  if (v.size() == 1) return v[0] == target;
  int greater_equal_k = 0;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] >= target && HasElementGreaterEqual(i - 2, i + 2, target, v)) {
      greater_equal_k++;
    }
    if (greater_equal_k >= 2) return true;
  }
  return false;
}

int main(void) {
  int tc, n, k;
  cin >> tc;
  while (tc--) {
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
      cin >> nums[i];
    }
    cout << (CanConvertAllTo(k, nums) ? "yes" : "no") << endl;
  }
  return 0;
}