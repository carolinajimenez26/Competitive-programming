#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define dbg(x) cout << #x << ": " << x << endl

void print(map<long int, long int> m) {
  for (auto& e : m) cout << e.first << "->" << e.second << endl;
}

void print(vector<long int> v) {
  for (auto& e : v) cout << e << " ";
  cout << endl;
}

int decreaseFrecuencies(int from, int n, vector<long int> &v, map<long int, long int> &m) {
  int i;
  for(i = from; i < v.size(); i++) {
    if (v[i] == n) {
      m[v[i]] -= 1;
      break;
    } else {
      m[v[i]] -= 1;
    }
  }
  return i + 1;
}

void machine(vector<long int> v, map<long int, long int> m) {
  int i = 0, j = 0;
  int max = numeric_limits<int>::min();
  while (i < v.size() and j < v.size()) {
    if (m[v[j]] >= 1) {
      if (j - i > max) max = j - i;
      i = decreaseFrecuencies(i, v[j], v, m);
    } else {
      m[v[j]] += 1;
      j++;
    }
  }
  if (j - i > max) max = j - i;
  cout << max << endl;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  long int tc, n, x;
  cin >> tc;
  map<long int, long int> frecuencies; // number, frequency
  vector<long int> v;
  while (tc--) {
    frecuencies.clear();
    v.clear();
    cin >> n;
    v.resize(n);
    int i = 0;
    while (n--) {
      cin >> x;
      v[i++] = x;
      if (!frecuencies.count(x)) {
        frecuencies[x] = 0;
      }
    }
    // print(frecuencies);
    // print(v);
    machine(v, frecuencies);
  }
  return 0;
}
