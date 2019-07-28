#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

#define dbg(x) cout << #x << ": " << x << endl

void print(map<int, char>& m) {
  for (auto e : m) {
    cout << e.first << " = " << e.second << endl;
  }
  cout << endl;
}

void print(set<int>& s) {
  for (auto e : s) cout << e << " ";
  cout << endl;
}

set<int> sieve(int N) {
  set<int> primes;
  vector<bool> result(N, true);
  result[0] = false;
  result[1] = false;
  for (int i = 2; i < N; i++) {
    if (result[i]) {
      for (int j = i * i; j < N; j += i) {
        result[j] = false;
      }
    }
  }

  for (int i = 0; i < result.size(); i++) {
    if (result[i]) primes.insert(i);
  }
  return primes;
}

pair<int, int> getNumbersMultipliedEqualTo(int target, set<int>& primes) {
  for (auto p : primes) {
    if (target % p == 0) {
      return {p, target / p};
    }
  }
  return {-1, -1};
}

set<int> helper(int next, vector<int>& ciphertext,
                const set<int>& primes) {
  set<int> used;
  used.insert(next);
  for (int i = 0; i < ciphertext.size(); i++) {
    if (((ciphertext[i] % next) != 0)) return {};
    next = ciphertext[i] / next;
    used.insert(next);
  }
  return used;
}

string decrypt(vector<int>& ciphertext, int start, map<int, char>& letter) {
  string ans;
  ans.push_back(letter[start]);
  for (auto it : ciphertext) {
    start = it / start;
    ans.push_back(letter[start]);
  }
  return ans;
}

string solve(set<int>& primes, vector<int>& ciphertext) {
  set<int> used;
  pair<int, int> p = getNumbersMultipliedEqualTo(ciphertext[0], primes);
  // cout << p.first << " * " << p.second << " = " << ciphertext[i] << endl;
  used = helper(p.first, ciphertext, primes);
  int start = p.first;
  if (used.size() == 0) {
    used = helper(p.second, ciphertext, primes);
    start = p.second;
  }
  map<int, char> letters;
  char cur = 'A';
  for (auto p : used) {
    letters[p] = cur;
    cur++;
  }
  // print(letters);
  // dbg(start);
  return decrypt(ciphertext, start, letters);
}

string recover(vector<int>& ciphertext, int N) {
  set<int> primes = sieve(N + 1);
  // primes.erase(2);
  // print(primes);
  return solve(primes, ciphertext);
}

int main(void) {
  int tc, N, L, c = 1;
  cin >> tc;
  while (tc--) {
    cin >> N >> L;
    vector<int> ciphertext(L);
    for (int i = 0; i < L; i++) {
      cin >> ciphertext[i];
    }
    cout << "Case #" << c << ": " << recover(ciphertext, N) << endl;
    c++;
  }
  return 0;
}
