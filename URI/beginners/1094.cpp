#include <bits/stdc++.h>
using namespace std;

int main(void){
  int cases, n, suma = 0, c = 0, r = 0, s = 0;
  char animal;
  cin >> cases;
  while(cases--){
    cin >> n >> animal;
    suma += n;
    animal == 'C' ? c += n : animal == 'R' ? r += n : s += n;
  }
  cout << "Total: " << suma << " cobaias" << endl;
  cout << "Total de coelhos: " << c << endl;
  cout << "Total de ratos: " << r << endl;
  cout << "Total de sapos: " << s << endl;
  cout << "Percentual de coelhos: " << fixed << setprecision(2) << ((float)c/suma)*100<< " %" << endl;
  cout << "Percentual de ratos: " << fixed << setprecision(2) << ((float)r/suma)*100<< " %" << endl;
  cout << "Percentual de sapos: " << fixed << setprecision(2) << ((float)s/suma)*100<< " %" << endl;
  return 0;
}
