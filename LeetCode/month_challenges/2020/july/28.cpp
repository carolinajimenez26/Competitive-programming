#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

struct Elem {
  char letter;
  int freq;

  bool operator<(const Elem& other) const {
    return freq < other.freq;
  }
};

class Solution {
private:
  void Print(vector<char>& v) {
    for (auto c : v) cout << c << " ";
    cout << endl;
  }

  void MoveWhileDiff(int& idx, const vector<char>& v, char letter) {
    while (idx < v.size() && v[idx] != letter) {
      idx++;
    }
  }

public:
  int leastInterval(vector<char>& tasks, int n) {
    int max = tasks.size() * (n == 0 ? 2 : n + 1);
    vector<char> ans(max, '-');

    unordered_map<char, int> freqs;
    for (auto letter : tasks) freqs[letter]++;

    priority_queue<Elem> pq;
    for (auto [letter, freq] : freqs) {
      pq.push({letter, freq});
    }

    unordered_map<char, int> last_pos;

    int init_idx = 0;
    while (!pq.empty()) {
      Elem e = pq.top();
      pq.pop();
      if (last_pos.count(e.letter) == 0) {
        MoveWhileDiff(init_idx, ans, '-');
        ans[init_idx] = e.letter;
        last_pos[e.letter] = init_idx;
      } else {
        int new_pos = last_pos[e.letter] + n + 1;
        MoveWhileDiff(new_pos, ans, '-');
        ans[new_pos] = e.letter;
        last_pos[e.letter] = new_pos;
      }
      e.freq--;
      if (e.freq > 0) pq.push(e);
    }

    while (ans.back() == '-') {
      ans.pop_back();
    }

    return ans.size();
  }
};

struct Test {
  vector<char> tasks;
  int n;
  int ans;
};

int main(void) {
  vector<Test> tests = {
    {
      {'A','A','A','A','A','A','B','B','B','C','C','D','D','D','D'}, 2, 16
    },
    {
      {'A','A','A','B','B','B'}, 3, 10
    },
    {
      {'A','A','A','B','B','B'}, 2, 8
    },
    {
      {'A','A','A','B','B','B'}, 0, 6
    },
    {
      {'A','A','A'}, 2, 7
    },
    {
      {'A','A','A'}, 1, 5
    },
    {
      {'A','A','B','B','C','C','D','D','E','E','F','F','G','G','H','H','I','I','J','J','K','K','L','L','M','M','N','N','O','O','P','P','Q','Q','R','R','S','S','T','T','U','U','V','V','W','W','X','X','Y','Y','Z','Z'},
      2, 52
    },
    {
      {'A','A','B','B','C','C','V','W','W','X','X','Y','Y','Z','Z'}, 2, 15
    },
    {
      {'V','W','W','X','X','Y','Y','Z','Z'}, 2, 9
    }
  };

  int tc = 0;
  bool succeed = true;
  Solution sol;
  for (auto test : tests) {
    int out = sol.leastInterval(test.tasks, test.n);
    if (out != test.ans) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.ans << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}