#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

string tostring(int &n) {
  stringstream ss;
  ss << n;
  string out;
  ss >> out;
  return out;
}

int main(void) {
  int t;
  long double n, money_lost, price, quantity, discount, new_price;
  cin >> t;
  while (t--) {
    cin >> n;
    money_lost = 0;
    for (int i = 0; i < n; i++) {
      cin >> price >> quantity >> discount;
      new_price = price + (price * (discount / 100));
      new_price -= (new_price * (discount / 100));
      money_lost += (quantity * (price - new_price));
    }
    int aux;
    aux = money_lost;
    string tmp;
    tmp = tostring(aux);
    cout << fixed << setprecision(11 - tmp.size()) << money_lost << endl;
  }
  return 0;
}
