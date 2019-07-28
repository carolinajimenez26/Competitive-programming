#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl

long int getWeight(string P) {
  long int w = 0, strength = 1;
  for (int i = 0; i < P.size(); i++) {
    if (P[i] == 'S') {
      w += strength;
    }
    if (P[i] == 'C') strength *= 2;
  }
  return w;
}

void swap(string &P, int index1, int index2) {
  // dbg(index1); dbg(index2);
  long int tmp = P[index1];
  P[index1] = P[index2];
  P[index2] = tmp;
}

pair<long int, long int> solver(string P, int idx, long int maxDamage) {
  long int hacks = 0, currentDamage = 0;
  // dbg(P);
  while (true) {
    // dbg(idx);
    currentDamage = getWeight(P);
    // dbg(currentDamage);
    if (currentDamage == maxDamage) break;
    if (maxDamage < currentDamage and idx == P.size() - 1) break;
    if (maxDamage > currentDamage) break;
    if (currentDamage > maxDamage) {
      swap(P, idx, idx + 1);
      idx++; // C moved
    }
    hacks++;
    // dbg(P);
    // dbg(hacks);
  }
  return make_pair(hacks, currentDamage);
}

int main(void) {
  int T, c = 1;
  long int D;
  pair<long int, long int> ans;
  string P;
  cin >> T;
  while (T--) {
    // M.clear();
    cin >> D >> P;
    int idx = -1;
    for (int i = 0; i < P.size(); i++) {
      if (P[i] == 'C') {
        idx = i;
        break;
      }
    }
    // dbg(idx);
    if (P.size() == 1 and P[0] == 'C') {
      if (P.size() <= D) cout << "Case #" << c << ": 0" << endl;
    } else {
      if (idx == -1) {
        if (P.size() <= D) cout << "Case #" << c << ": 0" << endl;
        else cout << "Case #" << c << ": IMPOSSIBLE" << endl;
      } else {
        // print(M);
        ans = solver(P, idx, D);
        if (ans.second <= D) cout << "Case #" << c << ": " << ans.first << endl;
        else cout << "Case #" << c << ": IMPOSSIBLE" << endl;
      }
    }
    c++;
  }
  return 0;
}
