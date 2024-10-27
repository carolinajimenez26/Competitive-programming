#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

string GetOponent(const string& player) {
  return (player == "alice" ? "bob" : "alice");
}

struct Stone {
  int greater, smaller;
  string owner;

  bool operator<(const Stone& other) const {
    if (greater == other.greater) return smaller > other.smaller;
    return greater > other.greater;
  }

  bool Get(bool isMax) {
    return isMax ? greater : smaller;
  }

  void Print() const {
    cout << "{" << greater << ", " << smaller << ", " << owner << "}";
  }
};

struct Freqs {
  unordered_map<string, int> freq;

  bool HasAny() {
    return freq["alice"] > 0 || freq["bob"] > 0 || freq["both"] > 0;
  }

  bool TakeMax(const string& player) {
    if (freq[player] > 0) {
      freq[player]--;
      return true;
    }
    if (freq["both"] > 0) {
      freq["both"]--;
      return true;
    }
    freq[GetOponent(player)]--;
    return false;
  }

  void Print() const {
    cout << "----" << endl;
    for (auto [owner, amount] : freq) {
      cout << owner << " -> " << amount << endl;
    }
    cout << "----" << endl;
  }
};

class Solution {
private:
  vector<int> alice_values; 
  vector<int> bob_values;

  map<Stone, Freqs> CreateInfo() {
    vector<Stone> stones;
    for (int i = 0; i < alice_values.size(); i++) {
      int greater = max(alice_values[i], bob_values[i]);
      int smaller = min(alice_values[i], bob_values[i]);
      string owner;
      if (greater == smaller) {
        owner = "both";
      } else {
        owner = greater == alice_values[i] ? "alice" : "bob";
      }
      stones.push_back({greater, smaller, owner});
    }
    sort(stones.begin(), stones.end());

    map<Stone, Freqs> info;
    for (auto stone : stones) {
      info[stone].freq[stone.owner]++;
    }
    return info;
  }

  void Print(const unordered_map<string, int>& hash_table) {
    for (auto [key, val] : hash_table) {
      cout << key << " -> " << val << endl;
    }
  }

  void Print(const map<Stone, Freqs>& m) {
    for (auto [stone, freq] : m) {
      stone.Print();
      cout << " -> " << endl;
      freq.Print();
      cout << endl;
    }
  }

public:
  int stoneGameVI(vector<int>& a, vector<int>& b) {
    alice_values = a;
    bob_values = b;
    map<Stone, Freqs> info = CreateInfo();
    unordered_map<string, int> points;
    string curr_player = "alice";
    // Print(info);

    for (auto [stone, freqs] : info) {
      while (freqs.HasAny()) {
        points[curr_player] += stone.Get(freqs.TakeMax(curr_player));
        curr_player = GetOponent(curr_player);
      }
    }
    // Print(points);
    if (points["alice"] == points["bob"]) return 0;
    if (points["alice"] > points["bob"]) return 1;
    return -1;
  }
};

struct Test {
  vector<int> alice_values, bob_values;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    { {1,3}, {2,1}, 1 },
    { {1,2}, {3,1}, 0 },
    { {2,4,3}, {1,6,7}, -1 },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.stoneGameVI(test.alice_values, test.bob_values);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}