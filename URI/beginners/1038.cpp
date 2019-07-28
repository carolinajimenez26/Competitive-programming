#include <bits/stdc++.h>
using namespace std;

int main(void){
  int A, B;
  float C[] = {4.00, 4.50, 5.00, 2.00, 1.50};
  cin >> A >> B;
  cout << "Total: R$ " << fixed << setprecision(2) << C[A - 1] * B << endl;
  return 0;
}
