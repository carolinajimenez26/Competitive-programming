#include <iostream>
#include <string>
#include <vector>
#define dbg(x) cout << #x << ": " << x << endl

using namespace std;

void print(vector<bool> v) {
  for (bool e : v) cout << e << " ";
  cout << endl;
}

void print(vector<int> v) {
  for (auto& e : v) cout << e << " ";
  cout << endl;
}

vector<int> getInfo(string S, char target) {
  vector<int> result;
  for (int i = 0; i < S.size(); i++) { // O (S.size())
    if (S[i] == target) result.push_back(i);
  }
  return result;
}

int minAddToMakeValid(string S) {
  vector<int> closingParenthesis = getInfo(S, ')');
  vector<int> openingParenthesis = getInfo(S, '(');
  vector<bool> used(S.size(), false);
  int count = 0;
  // print(closingParenthesis); print(openingParenthesis); print(used);
  int j = 0, i = 0;
  for (; i < closingParenthesis.size() && j < openingParenthesis.size(); i++) { // O (S.size())
    // dbg(i); dbg(j); dbg(count);
    if (openingParenthesis[j] < closingParenthesis[i] && !used[openingParenthesis[j]] && !used[closingParenthesis[i]]) {
      used[openingParenthesis[j]] = true;
      used[closingParenthesis[i]] = true;
      j++;
      // print(used);
    } else count++;
  }

  if (j < openingParenthesis.size()) count += (openingParenthesis.size() - j);
  if (i < closingParenthesis.size()) count += (closingParenthesis.size() - i);

  return count;
}

int main(void) {
  vector<string> inputs = {
    ")()))((",
    "())",
    "(((",
    "()",
    "()))((",
    ""
  };
  vector<int> expectedOutput = {
    5,
    1,
    3,
    0,
    4,
    0
  };

  bool success = true;

  for (int i = 0; i < inputs.size(); i++) {
    int output = minAddToMakeValid(inputs[i]);
    if (output != expectedOutput[i]) {
      success = false;
      cout << "Expected " << expectedOutput[i] << endl;
      cout << "Got " << output << endl;
    }
  }

  if (success) cout << "Good Job" << endl;
  else cout << "Keep trying" << endl;

  return 0;
}
