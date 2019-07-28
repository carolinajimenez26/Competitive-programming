#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define dbg(x) cout << #x << ": " << x << endl

void print(vector<int> &v) {
  for (auto& e : v) {
    cout << e << " ";
  }
  cout << endl;
}

struct myclass {
  bool operator() (int i,int j) { return (i > j);}
} myobject;

int getError(vector<int> v) {
  int middle1 = -1, middle2 = -1, i, j = 0, err = 0;
  if (v.size() % 2 == 0) {
    middle1 = (v.size() / 2) - 1;
    middle2 = v.size() / 2;
  } else middle1 = v.size() / 2;

  for (i = 0; i < middle1; i++, j++) { // left
    err += ((v[i] - j) * (v[i] - j));
  }

  err += ((v[i] - j) * (v[i] - j));
  if (middle2 != -1) {
    i++;
    err += ((v[i] - j) * (v[i] - j));
  }
  i++; j--;

  for (; i < v.size(); i++, j--) { // left
    err += ((v[i] - j) * (v[i] - j));
  }
  return err;
}

void solver(vector<int> &v, int case_number) {
  vector<int> v_sol(v.size());
  int idx1, idx2;
  int middle1 = -1, middle2 = -1;
  if (v.size() % 2 == 0) {

    middle1 = (v.size() / 2) - 1;
    middle2 = v.size() / 2;

    v_sol[middle1] = v[0];
    v_sol[middle2] = v[1];

    idx1 = middle1 - 1;
    idx2 = middle2 + 1;

    for (int i = 2; i < v.size(); i++, idx1--, idx2++) {
      v_sol[idx1] = v[i];
      i++;
      v_sol[idx2] = v[i];
    }

  } else {
    middle1 = v.size() / 2;
    v_sol[middle1] = v[0];

    idx1 = middle1 - 1;
    idx2 = middle1 + 1;
    for (int i = 1; i < v.size(); i++, idx1--, idx2++) {
      v_sol[idx1] = v[i];
      i++;
      v_sol[idx2] = v[i];
    }
  }

  // print(v_sol);

  cout << "Case #" << case_number << ": " << getError(v_sol) << endl;
}

int main(void) {
  int t, k, x, i;
  cin >> t;
  i = 1;
  vector<int> v;
  while (t--) {
    cin >> k;
    v.resize(k);
    for (int i = 0; i < k; i++) {
      cin >> x;
      v[i] = x;
    }
    // print(v);
    sort(v.begin(), v.end(), myobject);
    // print(v);
    solver(v, i);
    i++;
  }
  return 0;
}
