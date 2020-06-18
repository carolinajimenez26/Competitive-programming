#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool TrySwapping(const vector<int>& v, int idx, set<int>& nums) {
  for (int i = 0; i < v.size(); i++) {
    if (i != idx && nums.count(i) && v[i] % 2 != v[idx] % 2) {
      nums.erase(idx);
      nums.erase(i);
      return true;
    }
  }
  return false;
}

int MinSwaps(const vector<int>& v) {
  set<int> need_change;
  for (int i = 0; i < v.size(); i++) {
    if (i % 2 != v[i] % 2) {
      need_change.insert(i);
    }
  }
  if (need_change.empty()) return 0;
  int ans = 0;
  while (!need_change.empty()) {
    int i = *need_change.begin();
    bool succeed = TrySwapping(v, i, need_change);
    if (!succeed) return -1;
    ans++;
  }
  return ans;
}


int main(void) {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    cout << MinSwaps(v) << endl;
  }
}