// See https://www.codewhoop.com/array/rotation-in-place.html
#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
 if(b == 0) return a;
 return gcd(b, a % b);
}

void ArrayRotate(vector<int>& A, int k) {
  int d = -1, temp, j, n = A.size();
  if (n == 0) return;
  int gcd_ = gcd(n,k);
  for(int i = 0; i < gcd_; i++) {
    j = i;
    temp = A[i];
    while(true) {
      d = (j + k) % n;
      if(d == i) break;
      A[j] = A[d];
      j = d;
    }
    A[j] = temp;
  }
}

void print(const vector<int>& v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

struct Test {
  vector<int> nums;
  int d;
  vector<int> result;
};

int main(void) {
  vector<Test> tests = {
    {
      {1,2,3,4,5},
      2,
      {3,4,5,1,2}
    },
    {
      {1,2,3,4,5},
      4,
      {5,1,2,3,4}
    },
    {
      {1},
      4,
      {1}
    },
    {
      {},
      4,
      {}
    },
    {
      {1,2,3,4,5},
      5,
      {1,2,3,4,5}
    },
    {
      {1,2,3,4,5},
      6,
      {2,3,4,5,1}
    },
    {
      {1,2,3,4},
      2,
      {3,4,1,2}
    },
    {
      {41, 73, 89, 7, 10, 1, 59, 58, 84, 77, 77, 97, 58, 1, 86, 58, 26, 10, 86, 51},
      10,
      {77, 97, 58, 1, 86, 58, 26, 10, 86, 51, 41, 73, 89, 7, 10, 1, 59, 58, 84, 77}
    }
  };
  int tc = 0;
  bool succeed = true;

  for (auto test : tests) {
    vector<int> out = test.nums;
    ArrayRotate(out, test.d);
    if (out != test.result) {
      cout << "--------" << endl;
      succeed = false;
      cout << "Failed on test #" << tc << endl;
      cout << "Got: " << endl;
      print(out);
      cout << "Expected: " << endl;
      print(test.result);
      cout << "--------" << endl;
    }
    tc++;
  }

  if (succeed) cout << "Good job" << endl;
  else cout << "Keep trying" << endl;

  return 0;
}