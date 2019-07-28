#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string getCode(string word, unordered_map<char,int> frecuencies) {
  string result = "";
  // O (word.size())
  for (auto& letter : word) result.push_back(frecuencies[letter]);
  return result;
}

unordered_map<char, int> assignUniqueNumberToLetter(string word) {
  unordered_map<char,int> assignment;
  for (int i = 0; i < word.size(); i++) { // O (word.size())
    if (!assignment.count(word[i])) {
      assignment[word[i]] = i;
    }
  }
  return assignment;
}

vector<string> findAndReplacePattern(vector<string>& words, string pattern) { // O (word.size()**2)
  vector<string> result;
  string patternCode = getCode(pattern, assignUniqueNumberToLetter(pattern)); // O (word.size())
  for (auto& word : words) { // O (words.size())
    unordered_map<char,int> wordFrecuency = assignUniqueNumberToLetter(word); // O (word.size())
    string wordCode = getCode(word, wordFrecuency); // O (word.size())
    if (wordCode == patternCode) result.push_back(word);
  }
  return result;
}

void print(vector<string> v) {
  for (auto& e : v) cout << e << " ";
  cout << endl;
}

int main(void) {
  vector<vector<string>> inputs = {
    {"abc","deq","mee","aqq","dkd","ccc"},
    {"badc","abab","dddd","dede","yyxx"}
  };
  vector<string> patterns = {"abb", "baba"};
  vector<vector<string>> expectedOutput = {
    {"mee","aqq"},
    {"abab","dede"}
  };

  bool success = true;

  for (int i = 0; i < inputs.size(); i++) {
    vector<string> output = findAndReplacePattern(inputs[i], patterns[i]);
    if (output != expectedOutput[i]) {
      success = false;
      cout << "Expected ";
      print(expectedOutput[i]);
      cout << "Got ";
      print(output);
    }
  }

  if (success) cout << "Good Job" << endl;
  else cout << "Keep trying" << endl;

  return 0;
}
