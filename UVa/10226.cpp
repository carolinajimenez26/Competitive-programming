#include <bits/stdc++.h>
using namespace std;

int tonum(string &s) {
  stringstream ss;
  ss << s;
  int out;
  ss >> out;
  return out;
}

void getPercentage(double y, double total) {
  double x = (y / total);
  x *= 100;
  cout << fixed << setprecision(4) << x << endl;
}

void solver(map<string, int> trees, int count) {
  for (auto& tree : trees) {
    cout << tree.first << " ";
    getPercentage(tree.second, count);
  }
}

int main() {
  int tc, count = 0;
  string line, tc_s;
  getline(cin, tc_s);
  tc = tonum(tc_s);
  tc++;
  getline(cin, line);
  map<string, int> trees;
  bool show = false;
  while (tc) {
    getline(cin, line);
    if (line == "") show = true;//, dbg("blank");
    if (show) {
      if (tc != 1) solver(trees, count);
      trees.clear();
      count = 0;
      tc--;
      show = false;
      if (tc != 1 and tc != 0) cout << endl;
    }
    if (line != "") {
      if (trees.count(line)) trees[line] += 1;
      else trees[line] = 1;
      count++;
    }
  }
}
