#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool HasPalindrome(const vector<int>& vs, int size) {
  unordered_map<int, int> seen;
  for (int i = 0; i < size; i++) {
    if (seen[vs[i]] > 0) { // I've seen this element in my left
      //  there is only one of them seen and is not the one to my left
      if ((seen[vs[i]] == 1 && vs[i - 1] != vs[i]) || (seen[vs[i]] > 1)) {
        return true;
      }
    }
    seen[vs[i]]++;
  }
  return false;
}

int main(void) {
  int tc, N;
  vector<int> vs(5005);
  cin >> tc;
  while (tc) {
    cin >> N;
    for (int i = 0; i < N; i++) {
      cin >> vs[i];
    }
    cout << (HasPalindrome(vs, N) ? "YES" : "NO") << endl;
    tc--;
  }
  return 0;
}