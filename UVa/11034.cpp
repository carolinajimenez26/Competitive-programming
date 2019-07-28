#include <bits/stdc++.h>
using namespace std;
#define INF numeric_limits<int>::max()

void move(int &dir, int &sol) {
  dir = !dir;
  sol++;
}

void load(queue<int> &q, int capacity) {
  int current_capacity = capacity, e;
  while (!q.empty() and current_capacity) {
    e = q.front();
    if (e <= current_capacity) {
      q.pop();
      current_capacity -= e;
    } else break;
  }
}

void solver(queue<int> &left, queue<int> &right, int capacity) {
  int dir = 0; // dir: 0 left, 1 right
  int l, r, sol = 0;
  while (true) {
    if (left.empty() and right.empty()) break;

    l = left.empty() ? INF : left.front();
    r = right.empty() ? INF : right.front();

    if (!dir) { // ferry is in the left side
      load(left, capacity);
      move(dir, sol);
    } else { // ferry is in the right side
      load(right, capacity);
      move(dir, sol);
    }
  }
  cout << sol << endl;
}

int main(void) {
  int tc, l, m, car;
  string bank;
  cin >> tc;
  while(tc--) {
    queue<int> left, right;
    cin >> l >> m;
    l *= 100; // cms
    for(int i = 0; i < m; i++){
      cin >> car >> bank;
      bank == "right" ? right.push(car) : left.push(car);
    }
    solver(left, right, l);
  }
  return 0;
}
