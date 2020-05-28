#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define dbg(x) cout << #x << ": " << x << endl
using namespace std;

struct State {
  int actual, maybe, need;
};

int MaxAmountGrannies(const vector<int>& grannies, int i, State& st) {
  if (i >= grannies.size()) return st.actual;
  if (st.actual >= grannies[i]) {
    st.actual += 1;
    return MaxAmountGrannies(grannies, i + 1, st);
  }
  st.maybe += 1;
  st.need = max(st.need, grannies[i]);
  if (st.actual + st.maybe - 1 == st.need) {
    st.actual += st.maybe;
    st.maybe = 0;
    st.need = 0;
  }
  return MaxAmountGrannies(grannies, i + 1, st);
}

int MaxAmountGrannies(vector<int>& grannies) {
  sort(grannies.begin(), grannies.end());
  State st{1,0,0};
  return MaxAmountGrannies(grannies, 0, st);
}

int main(void) {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> grannies(n);
    for (int i = 0; i < n; i++) cin >> grannies[i];
    cout << MaxAmountGrannies(grannies) << endl;
  }
  return 0;
}