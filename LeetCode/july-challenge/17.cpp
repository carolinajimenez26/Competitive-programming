#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

struct Elem {
  int val, freq;

  bool operator<(const Elem& other) const {
    return freq > other.freq;
  }
};

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freqs;
    for (auto i : nums) freqs[i]++;
    priority_queue<Elem> pq;
    for (auto [n, freq] : freqs) {
      pq.push({n,freq});
      if (pq.size() > k) {
        pq.pop();
      }
    }
    
    vector<int> v;
    while (!pq.empty()) {
      v.push_back(pq.top().val);
      pq.pop();
    }
    return v;
  }
};

struct Test {
  vector<int> nums;
  int k;
  vector<int> ans;
};

void Print(const vector<int>& v) {
  for (auto e : v) cout << e << " ";
}

int main(void) {
  vector<Test> tests = {
    {
      {1,1,1,2,2,3},
      2,
      {1,2}
    },
    {
      {1},
      1,
      {1}
    },
    {
      {1,1,1,2,2,3},
      3,
      {1,2,3}
    },
    {
      {1,1,1,2,2,3},
      4,
      {1,2,3}
    },
    {
      {},
      1,
      {}
    },
    {
      {5,5,6,10,10},
      2,
      {5,10}
    },
    {
      {10,5,6,5,10},
      2,
      {5,10}
    },
    {
      {10,5,6,5,10,10},
      1,
      {10}
    },
    {
      {5,2,5,3,5,3,1,1,3},
      2,
      {3,5}
    }
  };
  int tc = 0;
  bool succeed = true;
  Solution sol;
  for (auto test : tests) {
    vector<int> out = sol.topKFrequent(test.nums, test.k);
    sort(out.begin(), out.end());
    if (test.ans != out) {
      cout << "Failed on test #" << tc << ". Found: "; 
      Print(out); 
      cout << ", expected ";
      Print(test.ans);
      cout << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}