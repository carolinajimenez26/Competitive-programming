#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
void print(const vector<T>& v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

void print(const vector<pair<int,int>>& vp) {
  for (auto p : vp) cout << p.first << ", " << p.second << endl;
}

// O (ops.size() * v.size())
void Operate(vector<int>& v, const vector<pair<int,int>>& ops, int ops_size) {
  for (int i = 0; i < ops_size; i++) { // O (ops.size())
    pair<int,int> op = ops[i];
    int l = op.first - 1, r = op.second;
    reverse(v.begin() + l, v.begin() + r); // O (v.size())
  }
}

// O (s.size())
void CreatePossibleOps(string& s, vector<string>& possible_ops) {
  do {
    possible_ops.push_back(s);
  } while (next_permutation(s.begin(), s.end()));
}

//  O (possible_ops.size() * (pos.size() * A.size()) )
int HowManyEquals(const vector<int>& A, const vector<pair<int,int>>& operations,
                  const vector<string>& possible_ops, const vector<int>& B) {
  int result = 0;
  for (auto pos : possible_ops) { // O (possible_ops.size())
    // pos is for e.g 321, meaning apply first operation 3, then 2, then 1
    vector<int> v = A; // O (A.size())
    for (int i = 0; i < pos.size(); i++) { // O (pos.size())
      int op_number = pos[i] - '0' - 1; // e.g 3 minus 1 to start in index 0
      pair<int,int> op = operations[op_number];
      int l = op.first - 1, r = op.second;
      reverse(v.begin() + l, v.begin() + r); // O (v.size())
    }
    // print(v);
    if (v == B) {
      result++;
    }
  }
  return result;
}

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main(void) {
  int tc, N, M;
  cin >> tc;
  while (tc) {
    cin >> N >> M;

    vector<int> A;
    vector<pair<int,int>> operations;
    vector<string> possible_ops;

    for (int i = 0; i < N; i++) {
      int n;
      cin >> n;
      A.push_back(n);
    }
    // print(A);
    char n = '1';
    string number = "";
    for (int i = 0; i < M; i++) {
      int l, r;
      cin >> l >> r;
      operations.push_back({l, r});
      number.push_back(n);
      n++;
    }
    // print(operations);
    vector<int> B = A;
    Operate(B, operations, M); // O (N * M)
    // print(B);
    CreatePossibleOps(number, possible_ops); // O (M!)
    // print(possible_ops);
    int equals_B = HowManyEquals(A, operations, possible_ops, B); //  O (M! * (M * N))
    int gcd_ = gcd(equals_B, possible_ops.size());
    cout << (equals_B / gcd_) << "/" << (possible_ops.size() / gcd_) << endl;
    tc--;
  }
  return 0;
}