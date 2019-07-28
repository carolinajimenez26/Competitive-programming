#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
#define N 1025
int board[N][N];
int killed[N][N];

struct data {
  int x, y, size;
  data (int x_, int y_, int size_) {
    x = x_;
    y = y_;
    size = size_;
  }
};

void print() {
  cout << "-----------------------------------" << endl;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << killed[i][j] << " ";
    }
    cout << endl;
  }
}

data findMax() {
  data sol(-1,-1,-1);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (killed[i][j] > sol.size) {
        sol.x = i;
        sol.y = j;
        sol.size = killed[i][j];
      }
    }
  }
  return sol;
}

// void sumPos(vector<pair<int,int>> v, int d) {
//   for (int i = 0; i < N; i++) {
//     for (int j = 0; j < N; j++) {
//       for (int k = 0; k < v.size(); k++) {
//         int x = v[k].first, y = v[k].second;
//         killed[i][j] += ((abs(i - x) <= d
//                           and abs(j - y) <= d) ?
//                           board[x][y] : 0);
//       }
//     }
//   }
// }

void sumPos(vector<pair<int,int>> v, int d) {
  for (int k = 0; k < v.size(); k++) {
    int x = v[k].first, y = v[k].second;
    int x_from = x - d, x_to = x + d;
    if (x_from < 0) x_from = 0;
    if (x_to > N) x_to = N;

    int y_from = y - d, y_to = y + d;
    if (y_from < 0) y_from = 0;
    if (y_to > N) y_to = N;

    for (int l = x_from; l <= x_to and l < N; l++) {
      for (int m = y_from; m <= y_to and m < N; m++) {
        killed[l][m] += board[x][y];
      }
    }
    // print();
  }
}

int main(void) {
  int tc, d, rat_population, x, y, size;
  vector<pair<int,int>> v;
  cin >> tc;
  while (tc--) {
    v.clear();
    memset(board, 0, sizeof board);
    memset(killed, 0, sizeof killed);
    cin >> d;
    cin >> rat_population;
    for (int i = 0; i < rat_population; i++) {
      cin >> x >> y >> size;
      board[x][y] = size;
      v.push_back(make_pair(x,y));
    }
    sumPos(v, d);
    data sol = findMax();
    cout << sol.x << " " << sol.y << " " << sol.size << endl;
  }
}
