#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define dbg(x) cout << #x << ": " << x << endl
long int finger_lengths[100001];
long int s_gloves_lengths[100001];

void solver(long int N) {
   bool back, front;
   back = front = true;

   long int j = N - 1;
   for(long int i = 0; i < N; i++, j--) {
     if (!back and !front) break;
     if (finger_lengths[i] > s_gloves_lengths[i]) front = false;
     if (finger_lengths[i] > s_gloves_lengths[j]) back = false;
   }

  if (back and front) cout << "both" << endl;
  if (!back and !front) cout << "none" << endl;
  if (back and !front) cout << "back" << endl;
  if (!back and front) cout << "front" << endl;
}

void print(int N) {
  cout << "finger_lengths" << endl;
  for (int i = 0; i < N; i++) {
    cout << finger_lengths[i] << " ";
  }
  cout << endl << "s_gloves_lengths" << endl;
  for (int i = 0; i < N; i++) {
    cout << s_gloves_lengths[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  int tc;
  long int N;
  cin >> tc;
  while (tc--) {
    cin >> N;
    for (int i = 0; i < N; i++) {
      cin >> finger_lengths[i];
    }
    for (int i = 0; i < N; i++) {
      cin >> s_gloves_lengths[i];
    }
    // print(N);
    solver(N);
  }
  return 0;
}
