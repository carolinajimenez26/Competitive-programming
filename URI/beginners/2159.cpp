#include <bits/stdc++.h>
using namespace std;

pair<double, double> func(double N){
  double P, M;
  P = N/log(N);
  M = 1.25506*N/log(N);
  return make_pair(P,M);
}

int main(void){
  double N;
  cin >> N;
  pair<double, double> ans = func(N);
  cout << fixed << setprecision(1) << ans.first << " ";
  cout << fixed << setprecision(1) << ans.second << endl;
  return 0;
}
