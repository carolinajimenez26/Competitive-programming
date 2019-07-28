#include <bits/stdc++.h>
using namespace std;
#define INF numeric_limits<int>::max()


void print(map<int, int> &sol) {
  for (auto& e : sol) {
    cout << e.second << endl;
  }
}

void move(int &dir, int &t_elapsed, int t) {
  dir = !dir;
  t_elapsed += t;
}

void load(queue<pair<int, int>> &q, int capacity, int &t_elapsed, int &dir, int t,
          map<int, int> &sol) {
  int current_capacity = 0;
  while (!q.empty()) {
    pair<int, int> e = q.front();
    if (e.first <= t_elapsed and current_capacity < capacity) {
      q.pop();
      sol[e.second] = t_elapsed + t;
      current_capacity++;
    } else break;
  }
}

void solver(queue<pair<int, int>> &left, queue<pair<int, int>> &right, int t,
            int capacity) {
  int t_elapsed = 0, dir = 0; // dir: 0 left, 1 right
  int l, r;
  bool flag;
  map<int, int> sol;
  while (true) {
    flag = false;
    if (left.empty() and right.empty()) break;

    l = left.empty() ? INF : left.front().first;
    r = right.empty() ? INF : right.front().first;

    if (!dir) { // ferry is in the left side
      if (l <= t_elapsed) {
        load(left, capacity, t_elapsed, dir, t, sol);
        move(dir, t_elapsed, t);
        flag = true;
      }
    } else {
      if (r <= t_elapsed) {
        load(right, capacity, t_elapsed, dir, t, sol);
        move(dir, t_elapsed, t);
        flag = true;
      }
    }
    if (!flag) {
      if (l < r) {
        if (t_elapsed < l) t_elapsed = l;

        if (!dir) { // left
          load(left, capacity, t_elapsed, dir, t, sol);
          move(dir, t_elapsed, t);
        } else {
          move(dir, t_elapsed, t);
          load(left, capacity, t_elapsed, dir, t, sol);
          move(dir, t_elapsed, t);
        }

      } else {
        if (t_elapsed < r) t_elapsed = r;

        if (dir) { // right
          load(right, capacity, t_elapsed, dir, t, sol);
          move(dir, t_elapsed, t);
        } else {
          move(dir, t_elapsed, t);
          load(right, capacity, t_elapsed, dir, t, sol);
          move(dir, t_elapsed, t);
        }

      }
    }
  }
  print(sol);
}

int main(void) {
  int tc, n, t, m, k;
  string bank;
  cin >> tc;
  while(tc--) {
    queue<pair<int, int>> left, right;
    cin >> n >> t >> m;
    for(int i = 0; i < m; i++){
      cin >> k >> bank;
      pair<int, int> tmp;
      if (bank == "right") {
        tmp = make_pair(k, i);
        right.push(tmp);
      } else {
        tmp = make_pair(k, i);
        left.push(tmp);
      }
    }
    solver(left, right, t, n);
    if (tc != 0) cout << endl;
  }
  return 0;
}
