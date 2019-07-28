#include <bits/stdc++.h>
using namespace std;

int main(void){
  string name;
  double salary, others;
  cin >> name >> salary >> others;
  cout << "TOTAL = R$ " << fixed << setprecision(2) << salary + (others * 0.15) << endl;
  return 0;
}
