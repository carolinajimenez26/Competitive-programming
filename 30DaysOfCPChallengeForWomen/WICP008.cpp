#include <iostream>
#include <vector>

using namespace std;

int HowManyHours(int K, const vector<int>& A, int A_size) {
  int hours = 0;
  for (int i = 0; i < A_size; i++) {
    if (A[i] <= K) {
      hours++;
    } else {
      int rest = A[i] % K;
      hours += (A[i] / K);
      hours += (rest == 0 ? 0 : 1);
    }
  }
  return hours;
}

int FindMinK(const vector<int>& A, int A_size, int H, int greater_A) {
  int left = 1, right = greater_A, mid; // try all possible Ks
  while (left < right) {
    mid = (left + right) / 2;
    if (HowManyHours(mid, A, A_size) <= H) { // the hours for that K works
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return left;
}

int main(void) {
  int tc, N, H;
  vector<int> A(1e5 + 5);
  cin >> tc;
  while (tc) {
    cin >> N >> H;
    int greater_A = 0;
    for (int i = 0; i < N; i++) {
      cin >> A[i];
      greater_A = max(greater_A, A[i]);
    }
    cout << FindMinK(A, N, H, greater_A) << endl;
    tc--;
  }
  return 0;
}