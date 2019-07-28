#include <bits/stdc++.h>
using namespace std;
char W[100][100];
unordered_map<char,int> H;

void init() {
  H['>'] = 0;
  H['<'] = 1;
  H['v'] = 2;
  H['^'] = 3;
}

bool FindWay(int rows, int cols, int dir, pair<int, int> pos) {
  if (pos.first >= cols && pos.first < 0 && pos.second >= rows \
  && pos.second < 0) return false;
  if (dir == 0) { //right
    for (int i = pos.first + 1; i < cols; i++) {
      if (W[pos.second][i] == '*') return true;
      if (W[pos.second][i] != '.') {
        return FindWay(rows,cols,H[ W[pos.second][i] ], make_pair(i,pos.second));
      }
    }
  }
  if (dir == 1) { //left
    for (int i = pos.first - 1; i >= 0; i--) {
      if (W[pos.second][i] == '*') return true;
      if (W[pos.second][i] != '.') {
        return FindWay(rows,cols,H[ W[pos.second][i] ], make_pair(i,pos.second));
      }
    }
  }
  if (dir == 2) { //down
    for (int i = pos.second + 1; i < rows; i++) {
      if (W[i][pos.first] == '*') return true;
      if (W[i][pos.first] != '.') {
        return FindWay(rows,cols,H[ W[i][pos.first] ], make_pair(pos.first,i));
      }
    }
  }
  if (dir == 3) { //up
    for (int i = pos.second - 1; i >= 0; i--) {
      if (W[i][pos.first] == '*') return true;
      if (W[i][pos.first] != '.') {
        return FindWay(rows,cols,H[ W[i][pos.first] ], make_pair(pos.first,i));
      }
    }
  }
  return false;
}

int main(void){
  int M, N;
  bool flag = false;
  init();
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> W[i][j];
      if (W[i][j] == '*') flag = true;
    }
  }
  if (flag == false) cout << "!" << endl;
  else {
    if(FindWay(M,N,0,make_pair(0,0))) cout << "*" << endl;
    else cout << "!" << endl;
  }
  return 0;
}
