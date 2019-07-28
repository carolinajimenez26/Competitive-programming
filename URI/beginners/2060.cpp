#include <bits/stdc++.h>
using namespace std;
int numbers[] = {2,3,4,5};
int multiples[] = {0,0,0,0};

int main(void){
  int N, number;
  cin >> N;
  for (size_t i = 0; i < N; i++) {
    cin >> number;
    for (size_t j = 0; j < 4; j++) {
      if (number % numbers[j] == 0)
        multiples[j] += 1;
    }
  }

  for (size_t i = 0; i < 4; i++) {
    cout << multiples[i] << " Multiplo(s) de " << numbers[i] << endl;
  }
  return 0;
}
