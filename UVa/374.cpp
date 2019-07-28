#include <bits/stdc++.h>
using namespace std;

long long int mod_pow(long long int base, long long int exp, long long int M) {
  long long int ans = 1;
  while (exp > 0) {
    if (exp % 2 != 0) ans = (ans * base) % M;
    exp /= 2;
    base = (base * base) % M;
  }
  return ans;
}

int main(void) {
  long long int B, P, M;
  while (cin >> B >> P >> M) {
    cout << mod_pow(B, P, M) << endl;
  }
  return 0;
}
