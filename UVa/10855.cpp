#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl

void appearances(char** S, int N, char** s, int n) {
  int cero = 0, ninety = 0, one_hundred_eighty = 0, two_hundred_seventy = 0; // degrees
  bool is_in;

  for (int h = 0; h < 4; h++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (i + n <= N and j + n <= N) {

          if (h == 0) { // Rotate 0°
            is_in = true;
            for (int ii = 0; ii < n and is_in; ii++) {
              for (int jj = 0; jj < n; jj++) {
                if (S[(i + ii) % N][(j + jj) % N] != s[ii][jj]) {
                  is_in = false;
                  break;
                }
              }
            }
            if (is_in) cero++;
          }

          if (h == 1) { // Rotate 90°
            is_in = true;
            int aux_i = 0;
            for (int jj = 0; jj < n and is_in; jj++, aux_i++) {
              int aux_j = 0;
              for (int ii = n - 1; ii >= 0; ii--, aux_j++) {
                if (S[(i + aux_i) % N][(j + aux_j) % N] != s[ii][jj]) {
                  is_in = false;
                  break;
                }
              }
            }
            if (is_in) ninety++;
          }

          if (h == 2) { // Rotate 180°
            is_in = true;
            int aux_i = 0;
            for (int ii = n - 1; ii >= 0 and is_in; ii--, aux_i++) {
              int aux_j = 0;
              for (int jj = n - 1; jj >= 0; jj--, aux_j++) {
                if (S[(i + aux_i) % N][(j + aux_j) % N] != s[ii][jj]) {
                  is_in = false;
                  break;
                }
              }
            }
            if (is_in) one_hundred_eighty++;
          }

          if (h == 3) { // Rotate 270°
            is_in = true;
            int aux_i = 0;
            for (int jj = n - 1; jj >= 0 and is_in; jj--, aux_i++) {
              int aux_j = 0;
              for (int ii = 0; ii < n; ii++, aux_j++) {
                if (S[(i + aux_i) % N][(j + aux_j) % N] != s[ii][jj]) {
                  is_in = false;
                  break;
                }
              }
            }
            if (is_in) two_hundred_seventy++;
          }

        }
      }
    }
  }

  cout << cero << " " << ninety << " " << one_hundred_eighty << " "
  << two_hundred_seventy << endl;
}

int main(void) {
  int N, n;
  char **S, **s;

  while (true) {
    cin >> N >> n;
    if (N == 0 and n == 0) break;

    S = new char*[N];
    for(int i = 0; i < N; i++) {
      S[i] = new char[N];
    }

    s = new char*[n];
    for(int i = 0; i < n; i++) {
      s[i] = new char[n];
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        cin >> S[i][j];
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> s[i][j];
      }
    }

    appearances(S, N, s, n);

    for(int i = 0; i < N; i++){
      delete []S[i];
    }
    delete []S;

    for(int i = 0; i < n; i++){
      delete []s[i];
    }

  }

  return 0;
}
