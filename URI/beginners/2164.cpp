#include <bits/stdc++.h>
using namespace std;

double Binet(int n){
  double a, b;
  a = pow((1 + sqrt(5))/2, n);
  b = pow((1 - sqrt(5))/2, n);
  return (a - b)/sqrt(5);
}

int main(void){
  int n;
  cin >> n;
  cout << fixed << setprecision(1) <<  Binet(n) << endl;
  return 0;
}
