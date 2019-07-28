#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int A[10001][10001];

void print(int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << A[i][j] << " ";
    }
    cout << endl;
  }
}

void print(queue<int> q) {
  int col;
  while (!q.empty()) {
    col = q.front();
    q.pop();
    cout << col + 1;
    if (q.size() != 0) cout << " ";
  }
  cout << endl;
}

void printAndPop(queue<int> &q, int row) {
  int col;
  while (!q.empty()) {
    col = q.front();
    q.pop();
    cout << A[col][row];
    if (q.size() != 0) cout << " ";
  }
  cout << endl;
}

void solver(int n, int m) {
  cout << m << " " << n << endl;
  queue<int> cols_out;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (A[j][i] != 0) {
        cols_out.push(j);
      }
    }
    cout << cols_out.size();
    if (cols_out.size() != 0) cout << " ";
    print(cols_out);
    printAndPop(cols_out, i);
  }
}

int main(void) {
  int n, m, x, rows, col, tmp, y;
  while (cin >> n >> m) {
    memset(A, 0, sizeof A);
    rows = 0;
    queue<int> cols_in;
    while (rows < n) {
      cin >> x;
      for (int i = 0; i < x; i++) {
        cin >> col;
        cols_in.push(col - 1);
      }
      for (int i = 0; i < x; i++) {
        tmp = cols_in.front();
        cols_in.pop();
        cin >> A[rows][tmp];
      }
      rows++;
    }
    // print(n, m);
    solver(n, m);
  }
  return 0;
}
