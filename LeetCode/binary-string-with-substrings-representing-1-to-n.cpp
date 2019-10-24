#include <iostream>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  long long ConvertToNumber(string& s) { // O (s.size())
    long long n = 0;
    for (const auto it : s) {
      n <<= 1;
      if (it == '1') n += 1;
    }
    return n;
  }

  set<string> CreateAllSubstrings(const string& S) { // O (S.size() * 60)
    set<string> result;
    for (int i = 0; i < S.size(); i++) { 
      string cur;
      for (int j = i; j < S.size() && (j - i + 1) <= 60; j++) {
        cur.push_back(S[j]);
        result.insert(cur);
      }
    }
    return result;
  }

  bool queryString(string S, int N) {
    set<string> substrings = CreateAllSubstrings(S); // at most 60 elements

    // Convert every posible substr in a integer
    set<long long> substrings_n;
    for (auto sstr : substrings) { // O (substrings.size()) = O (S.size()^2) = O (62^2)
      long long num = ConvertToNumber(sstr); // O (S.size())
      substrings_n.insert(num); // log substrings_n = O (log(substrings.size()) = O (log 62)
    }
    substrings_n.erase(0);

    // Create a vector with the substrings as numbers and sort it
    vector<long long> substrings_n_v(substrings_n.begin(), substrings_n.end());
    sort(substrings_n_v.begin(), substrings_n_v.end());

    // Check if substrings_n_v contains all numbers from 1 to N
    long long target = 1;
    for (auto e : substrings_n_v) { // at most O(N)
      if (e == target) {
        target++;
      } else {
        return false;
      }
      if (target > N) break;
    }

    return true;
  }
};

struct Test {
  string S;
  int N;
  bool expected;
};

int main(void) {
  vector<Test> tests = {
    {
      "0110",
      3,
      true
    },
    {
      "0110",
      4,
      false
    },
    {
      "0101011001101101010001001111110111100110110001001111001111111011010010101001011111010010001011011011",
      5,
      true
    },
    {
      "001111111000111011100110001001011100001101011001000100000001111100100001101100010010100111111100010101000000001010101011111001010111100000001110000001111000100001101010011010111101101000101101001110011000110110000110010111011100100101111000010011111001000001001000011011000111110010001010110101110011010000101001110000010111100001111011110000100000011000111111011101001011110111001110000011100100101001100001100111010010111111111000011110001110100010001000000101110000010100100111100010001111111110100001111000101001111110000011000001000001110011011011100010101010111110101110101110010111000110111110",
      30,
      true
    },
    {
      "11100111100110000101100111010110111001111010110100011011001000010000111000110011011011011111100111010010111101000001010111110100110010111111010110100101001111010011010000001100001011101110010111001000000111010001010010010010110111000010100111101010001110100110111100001100101000111100111010001101010000100000100000100001110110001101001101001001100111110111101101000010111110000101010001101101111001110100011100011011111110111000110001001101011011001001010010101110010000011101000100010000111111110001011001101010110010110111100010000000010011100101001001011100110000101001100110111000010000011001000000001000011100000000011111010011010011110000010111101111000001100100011101000011100101111000001010011110010110111000011001010001001100110100101010101010111101111101111001110111101100100110011100000110",
      40,
      true
    }
  };
  bool succeed = true;
  int test_case = 0;
  for (auto test : tests) {
    Solution sol;
    bool out = sol.queryString(test.S, test.N);
    if (out != test.expected) {
      succeed = false;
      cout << "Failed on test #" << test_case << endl;
    }
    test_case++;
  }

  if (succeed) cout << "Good job" << endl;
  else cout << "Keep trying" << endl;

  return 0;
}