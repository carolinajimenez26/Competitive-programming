#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl

void print(vector<vector<char>>& M) {
  for (int i = 0; i < M.size(); i++) {
    for (int j = 0; j < M[0].size(); j++) {
      cout << M[i][j];
    }
    cout << endl;
  }
}

void print(vector<int>& v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

set<pair<int,int>> fillWithKScapes(vector<vector<char>> &board, int K) {
  int persons_can_scape = 0, i, j;
  set<pair<int,int>> visited;
  for (i = 0; i < board.size(); i++) {
    for (j = 0; j < board[0].size(); j++) {
      if (persons_can_scape == K) return visited;
      board[i][j] = 'N';
      visited.insert(make_pair(i, j));
      persons_can_scape++;
    }
  }
  return visited;
}

bool exists(const pair<int,int>& pos, const pair<int,int>& max_pos) {
  return pos.first >= 0 && pos.first < max_pos.first &&
         pos.second >= 0 && pos.second < max_pos.second;
}

char getPosToUnvisited(const pair<int,int>& current_pos,
                       const set<pair<int,int>>& visited,
                       const pair<int, int> max_pos) {
  int row = current_pos.first, col = current_pos.second;
  pair<int, int> neigh_pos = make_pair(row - 1, col);
  if (exists(neigh_pos, max_pos) && !visited.count(neigh_pos)) return 'N';
  neigh_pos = make_pair(row + 1, col);
  if (exists(neigh_pos, max_pos) && !visited.count(neigh_pos)) return 'S';
  neigh_pos = make_pair(row, col + 1);
  if (exists(neigh_pos, max_pos) && !visited.count(neigh_pos)) return 'E';
  neigh_pos = make_pair(row, col - 1);
  if (exists(neigh_pos, max_pos) && !visited.count(neigh_pos)) return 'W';
}

void fillWithRest(vector<vector<char>> &board,
                  const set<pair<int,int>>& visited) {

  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
      if (!visited.count(make_pair(i,j))) {
        char point_to = getPosToUnvisited(make_pair(i, j), visited,
                                          make_pair(board.size(), board[0].size()));
        board[i][j] = point_to;
      }
    }
  }
}

bool gridEscape(vector<vector<char>> &board, int can_escape) {
  if ((board.size() * board[0].size()) - can_escape == 1) return false;
  pair<int,int> current_pos = make_pair(0, 0);
  set<pair<int,int>> visited = fillWithKScapes(board, can_escape);
  // print(board);
  fillWithRest(board, visited);
  // print(board);
  return true;
}

int main(void) {
  int T, R, C, K, current_case = 1;
  cin >> T;
  while (T--) {
    cin >> R >> C >> K;
    vector<vector<char>> result(R, vector<char>(C, '-'));
    cout << "Case #" << current_case << ": ";
    if (gridEscape(result, K)) {
      cout << "POSSIBLE" << endl;
      print(result);
    } else {
       cout << "IMPOSSIBLE" << endl;
     }
    current_case++;
  }
  return 0;
}
