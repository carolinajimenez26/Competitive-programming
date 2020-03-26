#include <iostream>
#include <vector>
#define MAX 1e6 + 5
#define dbg(x) cout << #x << ": " << x << endl

using namespace std;

void Sieve(vector<int>& v) {
  v[0] = 0;
  v[1] = 0;
  for (long long i = 2; i * i <= MAX; i++) {
    if (v[i]) {
      for (long long j = i * i; j < MAX; j += i) {
        v[j] = 0;
      }
    }
  }
}

void print(const vector<int>& v) {
  for (int i = 0; i < v.size(); i++) {
    cout << i << " -> " << v[i] << endl;
  }
}

int main(void) {
  int tc, N;
  vector<int> primes(MAX, 1);
  Sieve(primes);
  cin >> tc;
  // print(primes);
  while (tc) {
    cin >> N;
    if (primes[N]) {
      cout << "Divesh" << endl;
    } else {
      cout << "Tanya" << endl;
    }
    tc--;
  }
  return 0;
}