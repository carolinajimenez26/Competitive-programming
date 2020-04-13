#include <iostream>
#include <vector>

using namespace std;

struct Info {
  int h, l, r;
  vector<int> A;
  Info(vector<int> _A, int _h, int _l, int _r): A(_A), h(_h), l(_l), r(_r) {}
};

int FindMaxGoodSleep(int idx, int time, vector<vector<int>>& memo, const Info& input) {
  if (idx >= input.A.size()) {
    return 0;
  }
  if (memo[idx][time] != -1) {
    return memo[idx][time];
  }
  int new_time = (time + input.A[idx]) % input.h;
  int a = (new_time >= input.l && new_time <= input.r ? 1 : 0) +
          FindMaxGoodSleep(idx + 1, new_time, memo, input);
  new_time = (time + input.A[idx] - 1) % input.h;
  int b = (new_time >= input.l && new_time <= input.r ? 1 : 0) +
          FindMaxGoodSleep(idx + 1, new_time, memo, input);

  memo[idx][time] = max(a,b);
  return memo[idx][time];
}

int main(void) {
  int n, h, l, r;
  cin >> n >> h >> l >> r;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  Info info(A,h,l,r);
  vector<vector<int>> memo(n + 5, vector<int>(2005, -1));
  cout << FindMaxGoodSleep(0, 0, memo, info) << endl;
  return 0;
}