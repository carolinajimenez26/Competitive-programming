// See https://cp-algorithms.com/data_structures/sparse-table.html
#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#define dbg(x) cout << #x << ": " << x << endl
using namespace std;

class SparseTable {
private:
  vector<vector<int>> table;
  function<int(int,int)> combine;
  int K;
  int ZERO;

  inline int Pow2(int exp) { // returns 2^exp
    return 1 << exp;
  }

  // Time complexity: O (N log N)
  void Build(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
      table[i][0] = v[i];
    }

    for (int j = 1; j <= K; j++) {
      for (int i = 0; i + Pow2(j) <= v.size(); i++) {
        table[i][j] = combine(table[i][j-1], table[i + Pow2(j - 1)][j - 1]);
      }
    }
  }
public:
  // Space complexity: O (N log N)
  SparseTable(const vector<int>& v, function<int(int,int)> f, int zero) {
    ZERO = zero;
    K = log2(v.size()) + 1;
    combine = f;
    table.assign(v.size(), vector<int>(K));
    Build(v);
  }
  // Time complexity: O (log N)
  int Calculate(int L, int R) {
    int answer = ZERO;
    for(int j = K; j >= 0; j--) {
        if(L + Pow2(j) - 1 <= R) {
            answer = combine(answer, table[L][j]);
            L += Pow2(j);
        }
    }
    return answer;
  }

  function<int(int,int)> GetFunction() {
    return combine;
  }

  void Print() {
    cout << "    ";
    for (int col = 0; col <= K; col++) {
      cout << col << "| ";
    }
    cout << endl;

    for (int row = 0; row < table.size(); row++) {
      cout << row << " | ";
      for (int col = 0; col < table[0].size(); col++) {
        cout << table[row][col] << " ";
      }
      cout << endl;
    }
  }
};

struct Test {
  vector<int> v;
  int L, R;
};

int Apply(function<int(int,int)> f, Test test) {
  int result = test.v[test.L];
  for (int i = test.L + 1; i <= test.R; i++) {
    result = f(result, test.v[i]);
  }
  return result;
}

bool TestSparseTable(const vector<int>& v, SparseTable st) {
  cout << "testing SparseTable" << endl;
  function<int(int,int)> f = st.GetFunction();
  int N = v.size();
  vector<Test> tests = {
    {v, 0,0},
    {v, 0, N - 1},
    {v, 0, N/2},
    {v, N/2, N - 1}
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    cout << "Running test #" << tc << endl;
    dbg(test.L); dbg(test.R);
    int expected = Apply(f, test);
    int found = st.Calculate(test.L, test.R);
    if (expected != found) {
      cout << "Failed. Expected " << expected << ", found "
           << found << endl;
      succeed = false;
    } else {
      cout << "Passed." << endl;
    }
    tc++;
  }
  return succeed;
}

void Print(const vector<int>& v) {
  for (auto e : v) cout << e << " ";
  cout << endl << endl;
}

int main(void) {
  vector<int> v = {10,6,5,-7,9,-8,2,4,20};
  const int INF = numeric_limits<int>::max();
  SparseTable st_sum(v, [](int a, int b) { return a + b; }, 0);
  Print(v);
  st_sum.Print();
  bool succeed = true;
  succeed &= TestSparseTable(v, st_sum);
  SparseTable st_min(v, [](int a, int b) { return min(a,b); }, INF);
  succeed &= TestSparseTable(v, st_min);

  if (succeed) cout << "Good job!" << endl;
  else cout << "Keep trying." << endl;
  return 0;
}