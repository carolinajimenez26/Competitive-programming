#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

struct node {
  int val;
  int size;
  int next;
  node() : val(0), size(0), next(0) {}
};

void print(vector<node> v) {
  for (int i = 0; i < v.size(); i++) {
    node n = v[i];
    cout << "**********" << endl;
    cout << i << " " << n.val << " " << n.size << " " << n.next << endl;
    cout << "**********" << endl;
  }
}

int main(void) {
  int n, id, x, op;
  string s;
  vector<node> v_n;
  cin >> n;

  node source;
  v_n.push_back(source);

  while (n--) {
    cin >> id >> op;
    if (op == 0) { // push
      cin >> x;
      node n;
      n.val = x;
      n.size = v_n[id].size + 1;
      n.next = id;
      v_n.push_back(n);
      cout << n.size << endl;
    } else { // pop

      node tmp = v_n[id];
      node n = v_n[tmp.next];
      v_n.push_back(n);
      if (tmp.size == 0) cout << "-1" <<endl;
      else cout << tmp.val << endl;
    }
    // print(v_n);
  }
  return 0;
}
