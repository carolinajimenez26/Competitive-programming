#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000001; // 10^6
const int M = 1000000007; // 10^9 + 7
long long int fact[MAX];

long long int mod_pow(long long int base, long long int exp) {
  long long int ans = 1;
  while (exp > 0) {
    if (exp % 2 == 1) {
      ans = (ans * base) % M;
    }
    exp /= 2;
    base = (base * base) % M;
  }
  return ans;
}

long long int mod_inv(long long int n) {
  return mod_pow(n, M - 2);
}

void get_fact(int n) {
  fact[0] = 1;
  fact[1] = 1;
  for (int i = 2; i <= n; i++) {
    fact[i] = (fact[i - 1] * i) % M;
  }
}

bool excellent_number(int n, int a, int b) {
  long long int digit = 0;
  while (n > 0) {
    digit = (n % 10);
    if (digit != a && digit != b) return false;
    n /= 10;
  }
  return true;
}

long long int combinatorial(long long int x, int n) {
  // n! / (x! * (n - x)!)
  long long int ans = fact[n];
  ans = (ans * mod_inv(fact[x])) % M;
  ans = (ans * mod_inv(fact[n - x])) % M;
  return ans;
}

int main(void) {
  int a, b, n, b_aux;
  long long int ans = 0;
  cin >> a >> b >> n;
  get_fact(n);
  for (int a_aux = 0; a_aux <= n; a_aux++) {
    b_aux = n - a_aux; // e.g: aaabb
    if (excellent_number((a_aux * a) + (b_aux * b), a, b)) {
      ans = (ans + combinatorial(a_aux, n)) % M;
    }
  }
  cout << (ans % M) << endl;
  return 0;
}
