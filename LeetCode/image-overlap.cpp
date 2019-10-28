#include <iostream>
#include <vector>
#define dbg(x) cout << #x << ": " << x << endl

using namespace std;

class Solution {
private:
  vector<vector<int>> A; 
  vector<vector<int>> B;
  int size;
public:
  bool IsValid(int row, int col) {
    return row >= 0 && row < size && col >= 0 && col < size;
  } 

  int CountOverlap(int i, int j) {
    int sum = 0;
    for (int row = 0; row < size; row++) {
      for (int col = 0; col < size; col++) {
        if (IsValid(i + row, j + col) 
            && A[i + row][j + col] == 1 && B[row][col] == 1) {
          sum++;
        }

      }
    }
    return sum;
  }

  int largestOverlap(vector<vector<int>>& A_, vector<vector<int>>& B_) {
    A = A_;
    B = B_;
    size = A_.size();
    int best = 0;
    for (int row = 0; row < size; row++) {
      for (int col = 0; col < size; col++) {
        for (int delta_row = -1; delta_row <= 1; delta_row++) {
          for (int delta_col = -1; delta_col <= 1; delta_col++) {
            int sum = CountOverlap(row - size + 1 + delta_row, col - size + 1 + delta_col);
            best = max(best, sum);
          }
        }
      }
    }
    return best;
  }
};

struct Test {
  vector<vector<int>> A;
  vector<vector<int>> B;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    {
      {
        {1,1,0},
        {0,1,0},
        {0,1,0}
      },
      {
        {0,0,0},
        {0,1,1},
        {0,0,1}
      },
      3
    },
    {
      {
        {0,0,0,0,0},
        {0,1,0,0,0},
        {0,0,1,0,0},
        {0,0,0,0,1},
        {0,1,0,0,1}
      },
      {
        {1,0,1,1,1},
        {1,1,1,1,1},
        {1,1,1,1,1},
        {0,1,1,1,1},
        {1,0,1,1,1}
      },
      5
    },
    {
      {
        {1}
      },
      {
        {1}
      },
      1
    },
    {
      {
        {1,0},
        {1,1}
      },
      {
        {0,1},
        {1,0}
      },
      1
    }
  };
  bool succeed = true;

  int tc = 0;
  for (auto test : tests) {
    Solution sol;
    int out = sol.largestOverlap(test.A, test.B);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << endl;
      cout << "Got " << out << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }

  if (succeed) cout << "Good job" << endl;
  else cout << "Keep trying" << endl;
  
  return 0;
}