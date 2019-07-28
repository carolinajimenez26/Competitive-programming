#include <bits/stdc++.h>
using namespace std;

int main(void){
  float salary, aux, n;
  cin >> salary;
  if (salary >= 0 && salary <= 400) n = 15;
  else if (salary >= 400.01 && salary <= 800) n = 12;
  else if (salary >= 800.01 && salary <= 1200) n = 10;
  else if (salary >= 1200.01 && salary <= 2000) n = 7;
  else if (salary >= 2000.01) n = 4;

  cout << "Novo salario: " << fixed << setprecision(2) << salary + salary * (n / 100) << endl;
  cout << "Reajuste ganho: " << fixed << setprecision(2) << salary * (n / 100) << endl;
  cout << "Em percentual: " << (int)n << " %" << endl;

  return 0;
}
