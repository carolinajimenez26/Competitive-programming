#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string line;
  int tc = 1;
  while (getline(cin, line)) {
    if (line == "end") break;
    vector<stack<char> > vs(1); // minimum one stack
    vs[0].push(line[0]);
    for (int i = 1; i < line.length(); i++) {
      bool flag = false;
      for (int j = 0; j < vs.size(); j++) {
        if (line[i] <= vs[j].top()) {
          vs[j].push(line[i]);
          flag = true;
          break;
        }
      }
      if (!flag) {
        stack<char> tmp;
        tmp.push(line[i]);
        vs.push_back(tmp);
      }
    }
    cout << "Case " << tc++ << ": " << vs.size() << endl;
  }
  return 0;
}
