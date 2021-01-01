#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl

#define assertm(exp, msg) assert(((void)msg, exp))
using int64 = long long int;

struct Tape {
  Tape* prev;
  int64 prev_times;
  string extra;
  int64 size;

  Tape(Tape* prev_, int64 times) : prev(prev_), prev_times(times) {
    size = ((prev_ == nullptr) ? 0 : prev_->size) * times;
  }

  void Add(char c) {
    extra.push_back(c);
    size++;
  }

  int64 PrevSize() {
    return (prev == nullptr) ? 0 : prev->size;
  }

  string Get(int64 k) {
    assertm(k < size, "invalid id");
    int64 total_prev = PrevSize() * prev_times;
    if (k < total_prev) {
      return prev->Get(k % PrevSize());
    }
    return string(1, extra[k - total_prev]);
  }
};

class Solution {  
public:
  string decodeAtIndex(string S, int K) {
    vector<Tape*> all;
    all.push_back(new Tape(nullptr, 0));
    for (auto c : S) {
      if (isdigit(c)) {
        int times = ToInt(c);
        Tape* last = all.back();
        all.push_back(new Tape(last, times));
      } else {
        all.back()->Add(c);
      }
      if (all.back()->size >= K) {
        break;
      }
    }
    return all.back()->Get(K-1);
  }

private:
  int ToInt(char c) {
    assertm(isdigit(c), "ToNumber should receive a valid char");
    return (c - '0');
  }
};

struct Test {
  string S;
  int K;
  string expected;
};

int main(void) {
  vector<Test> tests = {
    { "leet2code3", 10, "o" }, // leetleetcodeleetleetcodeleetleetcode
    { "a2b2c2d2", 15, "d" },
    { "leet2code3", 35, "d" },
    { "leet2code3", 36, "e" },
    { "ha22", 5, "h" },
    { "a2345678999999999999999", 1, "a" },
    { "ab", 1, "a" },
    { "a2b", 3, "b" }, // aab
    { "a2b2", 6, "b" }, // aabaab
    { "a22b", 5, "b" }, // aaaab
    { "aa23b2", 13, "b" }, // aaaaaaaaaaaabaaaaaaaaaaaab
    { "aa23b2", 26, "b" }, // aaaaaaaaaaaabaaaaaaaaaaaab
    { "y959q969u3hb22odq595", 222280, "y"},
    { "y959q969u3hb22odq595", 222280369, "y" },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    string out = sol.decodeAtIndex(test.S, test.K);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out 
           << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}