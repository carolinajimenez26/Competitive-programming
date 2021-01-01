#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    unordered_map<int,int> freqsAB = Combine(A, B);
    unordered_map<int,int> freqsCD = Combine(C, D);
    
    int ans = 0;
    for (auto [elem, freq] : freqsAB) {
      ans += (freq * freqsCD[-elem]);
    }

    return ans;
  }
private:
  unordered_map<int, int> Combine(const vector<int>& A, const vector<int>& B) {
    unordered_map<int,int> freqs;
    for (int i = 0; i < A.size(); i++) {
      for (int j = 0; j < B.size(); j++) {
        freqs[A[i] + B[j]]++;
      }
    }
    return freqs;
  }
};

int main(void) {
  return 0;
}