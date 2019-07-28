#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define dbg(x) cout << #x << ": " << x << endl

struct compare {
  bool operator() (const int& l, const int& r) {
      return l > r;
  }
};

void print(priority_queue<int, vector<int>, compare > q) {
  dbg("print");
  while (!q.empty()) {
    cout << q.top() << endl;
    q.pop();
  }
}

int main(void) {
  int n, x, ans, tmp;
  while (cin >> n) {
    ans = 0;
    priority_queue<int, vector<int>, compare > q;
    if (!n) break;
    for (int i = 0; i < n; i++) {
      cin >> x;
      q.push(x);
    }
    if (q.size() > 1) {
      tmp = q.top();
      q.pop();
      tmp += q.top();
      q.pop();
      ans += tmp;
      q.push(tmp);
      while (q.size() > 1) {
        tmp = q.top();
        q.pop();
        tmp += q.top();
        q.pop();
        ans += tmp;
        q.push(tmp);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
