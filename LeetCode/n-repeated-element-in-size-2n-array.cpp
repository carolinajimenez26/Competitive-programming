#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int repeatedNTimes(vector<int>& A) {
    unordered_map<int, int> freqs;
    for (auto e : A) {
      freqs[e]++;
    }
    for (auto freq : freqs) {
      if (freq.second == (A.size() / 2)) {
        return freq.first;
      }
    }
    return -1;
  }
};

int main(void) {
  return 0;
}