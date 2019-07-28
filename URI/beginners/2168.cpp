#include <bits/stdc++.h>
using namespace std;
bool M[105][105];
char ans[105][105];

void showMatrix(int N){
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < N; j++) {
      cout << ans[i][j];
    }
    cout << endl;
  }
}

void init(int N){
  for (size_t i = 0; i <= N; i++) {
    for (size_t j = 0; j <= N; j++) {
      cin >> M[i][j];
    }
  }
}

int main(void){
  int N, sum = 0;
  cin >> N;
  init(N);

  for (size_t i = 0; i < N ; i++) {
    for (size_t j = 0; j < N ; j++) {
      for (size_t k = 0; k < 2; k++) {
        for (size_t l = 0; l < 2; l++) {
          sum += M[k + i][l + j];
        }
      }
      if (sum >= 2) ans[i][j] = 'S';
      else ans[i][j] = 'U';
      sum = 0;
    }
  }

  showMatrix(N);
  return 0;
}
