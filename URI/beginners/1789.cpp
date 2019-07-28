#include <bits/stdc++.h>
using namespace std;

int main(void){
  unsigned int N, M;
  bool uno = false, dos = false, tres = false;
  while (cin >> N) {
    while (N--) {
      cin >> M;
      if (M < 10 && !uno) uno = true;
      if (M >= 10 && M < 20 && !dos) dos = true;
      if (M >= 20 && !tres) tres = true;
    }
    if (tres) cout << 3 << endl;
    else if (dos) cout << 2 << endl;
    else if (uno) cout << 1 << endl;
    uno = dos = tres = false;
  }
  return 0;
}
