#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
// #define INF numeric_limits<int>::max()

double dist(pair<int,int> p1, pair<int,int> p2) {
  int x1 = p1.first, x2 = p2.first;
  int y1 = p1.second, y2 = p2.second;
  // dbg(x1); dbg(x2); dbg(y1); dbg(y2);
  return sqrt(((x1 - x2)*(x1 - x2)) + ((y1 - y2)*(y1 - y2)));
}

int main(void) {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  int n, x, y;
  cin >> n;
  vector<pair<int,int>> stars;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    stars.push_back(make_pair(x,y));
  }
  double min = numeric_limits<double>::max();
  for (int i = 0; i < n; i++) {
    // dbg(i);
    for (int j = 0; j < n; j++) {
      // dbg(j);
      if (i != j) {
        double tmp = dist(stars[i], stars[j]);
        if (tmp < min) min = tmp;
      }
    }
  }
  cout << fixed << setprecision(9) << min << endl;
  return 0;
}
