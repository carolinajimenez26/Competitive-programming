#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#define dbg(x) cout << #x << ": " << x << endl

using namespace std;

int removeUntilFind(char target, string s, int index,
                    unordered_map<char,int> &frecuencies) { // O (s.size())
  char current;
  while (true) { // O (s.size())
    current = s[index];
    frecuencies.erase(s[index]); // O (1)
    index++;
    if (current == target) {
      break;
    }
  }
  return index;
}

int lengthOfLongestSubstring(string s) { // O (s.size())
  if (s.size() == 0) return 0;
  unordered_map<char,int> frecuencies;
  int longestSize = 0;
  string solution = "";
  int i = 0, j = 1;

  frecuencies[s[i]] = 1;

  while (j < s.size()) { // O (s.size())
    dbg(i); dbg(j);
    if (frecuencies.count(s[j]) == 0) { // O (1)
      frecuencies[s[j]] = 1; // O (1)
      j++;
    } else {
      longestSize = max(longestSize, (j - i));
      i = removeUntilFind(s[j], s, i, frecuencies); // O (s.size())
      frecuencies[s[j]] += 1;
      j++;
    }
  }

  return max(longestSize, (j - i));
}

int main(void) {
  vector<string> inputs = {
    "abcabcbb",
    "bbbbb",
    "pwwkew",
    "abcdecf",
    "au",
    "aukjbfdjkafnlksdfnmoasdjfaksdlfnlkasdnfaskdfnadks"
  };
  vector<int> outputs = { 3, 1, 3, 5, 2, 9 };
  bool success = true;

  for (int i = 0; i < inputs.size(); i++) {
    int output = lengthOfLongestSubstring(inputs[i]);
    if (output != outputs[i]) {
      cout << "Output: " << output << ", expected: " << outputs[i] << endl;
      success = false;
    }
  }

  if (success) cout << "Good Job" << endl;
  else cout << "Keep Trying" << endl;

  return 0;
}
