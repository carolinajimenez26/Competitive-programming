#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  while (cin >> n) {
    if (!n) break;
    bitset<32> a, b;
    string binary = bitset<32>(n).to_string(); //to binary
    int j = 0, turn = 0; // 0 a, 1 b
    for (int i = binary.length() - 1; i >= 0; i--, j++) {
      if (binary[i] == '1') {
        if (turn) { // odd
          b[j] = 1;
        } else { // pair
          a[j] = 1;
        }
        turn = not turn;
      }
    }
    cout << a.to_ulong() << " " << b.to_ulong() << endl;
  }
  return 0;
}
