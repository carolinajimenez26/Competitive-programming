#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
private:
  int total_digits, K;
  vector<int> ans;

  // O (log2 N)
  bool IsValid(int n) {
    if (n / 10 == 0) return true;
    int x = n % 100; // gets last 2 digits
    int a = x % 10;
    int b = x / 10;
    if (abs(a - b) != K) {
      return false;
    }
    return IsValid(n / 10);
  }

  void numsSameConsecDiffHandler(int curr, int x) {
    if (x == 1) {
      ans.push_back(curr);
      return;
    }
    int last_digit = (curr / x) % 10;
    int op1 = last_digit - K; // last_digit - K = desired_next_number
    int op2 = last_digit + K; // last_digit + K = desired_next_number

    if (op1 >= 0 && op1 <= 9) {
      int x1 = x / 10;
      int curr1 = curr + (op1 * x1);
      numsSameConsecDiffHandler(curr1, x1);
    }
    if (op2 >= 0 && op2 <= 9 && op2 != op1) {
      int x2 = x / 10;
      int curr2 = curr + (op2 * x2);
      numsSameConsecDiffHandler(curr2, x2);
    }
  }

public:
  // we generate numbers from 10^(K - 1) to 10^K, 
  // and the amount of numbers in that range is maximum 9 * 10^(K - 1)
  // O ((9 * 10^(K - 1)) * N), where N = total_digits
  vector<int> numsSameConsecDiffSlow(int _total_digits, int _K) {
    total_digits = _total_digits;
    K = _K;
    int from = total_digits == 1 ? 0 : pow(10, total_digits - 1);
    int to = pow(10, total_digits);
    while (from < to) {
      if (IsValid(from)) {
        ans.push_back(from);
      }
      from++;
    }
    return ans;
  }

  // for every possible initial digit (from 1 to 9), check the 2 possibles next
  // digits, and do it until we have the number of digits equals N
  // O (9 * (2 ^ (N - 1))), where N = total_digits
  vector<int> numsSameConsecDiff(int _total_digits, int _K) {
    total_digits = _total_digits;
    K = _K;
    if (total_digits == 1) return {0,1,2,3,4,5,6,7,8,9};
    for (int digit = 1; digit <= 9; digit++) { // try all digits for first position
      int x = pow(10, total_digits - 1);
      int curr = digit * x;
      numsSameConsecDiffHandler(curr, x);
    }
    return ans;
  }
};

struct Test {
  int n, k;
  vector<int> ans;
};

void Print(const vector<int>& v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

int main(void) {
  vector<Test> tests = { // you should define your Test structure
    { 1, 1, {0,1,2,3,4,5,6,7,8,9} },
    { 1, 10, {0,1,2,3,4,5,6,7,8,9} },
    { 2, 1, {10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98} },
    { 3, 7, {181,292,707,818,929} },
    { 9, 9, {909090909} },
    { 2, 0, {11,22,33,44,55,66,77,88,99} },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    vector<int> out = sol.numsSameConsecDiff(test.n, test.k);
    if (out != test.ans) {
      cout << "Failed on test #" << tc << ". Found " << endl;
      Print(out);
      cout << "Expected " << endl;
      Print(test.ans);
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}