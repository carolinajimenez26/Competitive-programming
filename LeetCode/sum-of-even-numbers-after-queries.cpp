#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  int CountEvens(const vector<int>& v) {
    int res = 0;
    for (auto e : v) {
      if (e % 2 == 0) res += e;
    }
    return res;
  }
public:
  vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
    vector<int> result;
    int evenNumbers = CountEvens(A);
    for (auto query : queries) {
      int val = query[0];
      int idx = query[1];
      int tmp = A[idx];
      A[idx] += val;
      if (A[idx] % 2 != 0 && tmp % 2 == 0) { // The new element is not even and it was even before the sum
        evenNumbers -= tmp;
      }
      if (A[idx] % 2 == 0) {
        if (tmp % 2 != 0) { // The element wasn't even before the sum, so add the new value
          evenNumbers += A[idx];
        } else { // The element was already even, so add/substract the difference
          int rest = A[idx] - tmp; //  tmp = 8, A[idx] = 10 => rest = -2.
          evenNumbers += rest;
        }
      }
      result.push_back(evenNumbers);
    }
    return result;
  }
};

void print(const vector<int>& v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

int main(void) {
  Solution sol;
  vector<int> A = {1,2,3,4};
  vector<vector<int>> queries = {{1,0},{-3,1},{-4,0},{2,3}};
  vector<int> res = sol.sumEvenAfterQueries(A, queries);
  print(res);
  return 0;
}