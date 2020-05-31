#include <iostream>
#include <vector>
using namespace std;

int MinimunCostPainting(vector<vector<char>>& v, int price1, int price2) {
  int ans = 0;
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[0].size(); j++) {
      if (v[i][j] == '.') {
        if (j + 1 < v[0].size() && v[i][j + 1] == '.') {
          ans += min(2 * price1, price2);
          v[i][j] = '*';
          v[i][j + 1] = '*';
        } else {
          ans += price1;
          v[i][j] = '*';
        }
      }
    }
  }
  return ans;
}

int main(void) {
  int tc;
  cin >> tc;
  while (tc--) {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<vector<char>> a(n, vector<char>(m,'x'));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    cout << MinimunCostPainting(a, x, y) << endl;
  }
  return 0;
}