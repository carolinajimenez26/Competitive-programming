#include <iostream>
#include <unordered_map>

using namespace std;

void SwapPairs(string& s) {
  for (int i = 0; i < s.size(); i += 2) {
    if ((i + 1) < s.size()) {
      char tmp = s[i];
      s[i] = s[i + 1];
      s[i + 1] = tmp;
    }
  }
}

void Encode(string& s, unordered_map<char, int>& alphabet_n,
            unordered_map<int, char>& reversed_alphabet_n) {
  for (int i = 0; i < s.size(); i++) {
    char letter = s[i], letter_before;
    letter_before = letter - 1;
    int x = alphabet_n[letter] + 25 - (2 * alphabet_n[letter_before]);
    s[i] = reversed_alphabet_n[x];
  }
}

template <class T1, class T2>
void print(const unordered_map<T1, T2>& m) {
  for (auto e : m) {
    cout << e.first << " -> " << e.second << endl;
  }
}

int main(void) {
  int tc, N;
  string s;
  unordered_map<char, int> alphabet_n;
  unordered_map<int, char> reversed_alphabet_n;
  char letter = 'a';
  for (int i = 1; i <= 26; i++, letter++) {
    alphabet_n[letter] = i;
    reversed_alphabet_n[i] = letter;
  }
  // print(alphabet_n);
  // print(reversed_alphabet_n);
  cin >> tc;
  while (tc) {
    cin >> N >> s;
    SwapPairs(s);
    Encode(s, alphabet_n, reversed_alphabet_n);
    cout << s << endl;
    tc--;
  }
  return 0;
}