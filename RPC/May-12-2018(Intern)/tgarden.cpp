#include<bits/stdc++.h>
using namespace std;
#define endl '\n'


// if there is not an inedible flowers
bool not_in(pair<int, int> pos, set<pair<int,int>> &s) {
  set<pair<int,int>>::iterator it;
  it = s.find(pos);
  return it == s.end();
}

// generates new invaders
set<pair<int, int>> generate(set<pair<int,int>> &flowers, set<pair<int,int>> &invaders,
                               set<pair<int, int>> &visited) {
  set<pair<int, int>> q_next;
  queue<pair<int, int>> q_curr;
  for (auto it : invaders) {
    q_curr.push(it);
  }

  while(!q_curr.empty()) {
    pair<int, int> v = q_curr.front();
    q_curr.pop();

    int x = v.first, y = v.second;
    if (not_in(make_pair(x, y - 1), flowers) && not_in(make_pair(x, y - 1), visited)) { // up
      q_next.insert(make_pair(x, y - 1));
      visited.insert(make_pair(x, y - 1));
    }
    if (not_in(make_pair(x, y + 1), flowers) && not_in(make_pair(x, y + 1), visited)) { // down
      q_next.insert(make_pair(x, y + 1));
      visited.insert(make_pair(x, y + 1));
    }
    if (not_in(make_pair(x - 1, y), flowers) && not_in(make_pair(x - 1, y), visited)) { // left
      q_next.insert(make_pair(x - 1, y));
      visited.insert(make_pair(x - 1, y));
    }
    if (not_in(make_pair(x + 1, y), flowers) && not_in(make_pair(x + 1, y), visited)) { // right
      q_next.insert(make_pair(x + 1, y));
      visited.insert(make_pair(x + 1, y));
    }
  }
  return q_next;
}

int main(void) {
  int n, m, t, x, y, ans = 0;
  cin >> n >> m >> t;
  set<pair<int,int>> flowers, invaders, visited, q;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    invaders.insert(make_pair(x, y));
  }
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    flowers.insert(make_pair(x, y));
  }
  for (auto it : invaders) {
    visited.insert(it);
  }
  while (t != 0) {
    q = generate(flowers, invaders, visited);
    invaders = q;
    t--;
  }
  cout << visited.size() << endl;
  return 0;
}
