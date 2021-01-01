#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool canFormArray(vector<int>& arr_, vector<vector<int>>& pieces) {
    arr = arr_;
    unordered_map<int, vector<int>> piece_by_head;
    for (auto piece : pieces) {
      piece_by_head[piece[0]] = piece;
    }
    for (int i = 0; i < arr.size();) {
      if (piece_by_head.count(arr[i]) == 0 || !Matches(piece_by_head[arr[i]], i)) {
        return false;
      }
      i += piece_by_head[arr[i]].size();
    }
    return true;
  }
private:
  vector<int> arr;

  bool Matches(const vector<int>& piece, int from) {
    if (piece.size() > arr.size() - from) {
      return false;
    }
    for (int i = 0; i < piece.size(); i++, from++) {
      if (piece[i] != arr[from]) {
        return false;
      }
    }
    return true;
  }
};

struct Test {
  vector<int> arr;
  vector<vector<int>> pieces;
  bool expected;
};

int main(void) {
  vector<Test> tests = {
    { {85}, {{85}}, true },
    { {85}, {{1}}, false },
    { {85}, {}, false },
    { {15,88}, {{88},{15}}, true },
    { {49,18,16}, {{16,18,49}}, false },
    { {91,4,64,78}, {{78},{4,64},{91}}, true },
    { {1,3,5,7}, {{2,4,6,8}}, false },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    bool out = sol.canFormArray(test.arr, test.pieces);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}