#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
#define MAX 2e10 + 5
#define dbg(x) cout << #x << ": " << x << endl

using namespace std;
using int64 =  long long int;

bool FindPath(int64 x, int64 y, int64 time, string& path, int64 max_depth) {
  if (x == 0 && y == 0) {
    return true;
  }
  if (max_depth == path.size()) {
    return false;
  }
  vector<int> x_dir = {0,  1,  0, -1};
  vector<int> y_dir = {1,  0, -1,  0};
  vector<char> dir = {'N','E','S','W'};
  int64 times = (1 << time);
  for (int i = 0; i < y_dir.size(); i++) {
    path.push_back(dir[i]);
    int64 next_x = x + (x_dir[i] * times);
    int64 next_y = y + (y_dir[i] * times);
    if (FindPath(next_x, next_y, time + 1, path, max_depth)) {
      return true;
    }
    path.pop_back();
  }
  return false;
}

string Reverse(const string& s) {
  string result = "";
  for (auto letter : s) {
    if(letter == 'N') {
      result.push_back('S');
    }
    if(letter == 'S') {
      result.push_back('N');
    }
    if(letter == 'W') {
      result.push_back('E');
    }
    if(letter == 'E') {
      result.push_back('W');
    }
  }
  return result;
}

int main(void) {
  int tc;
  int64 x, y;
  cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cin >> x >> y;
    string r = "";
    int64 z = abs(x) + abs(y);
    int64 max_depth = ceil(log2(z + 1));
    cout << "Case #" << i << ": " << (FindPath(x,y,0,r,max_depth) == false ? "IMPOSSIBLE" : Reverse(r)) << endl;
  }
  return 0;
}