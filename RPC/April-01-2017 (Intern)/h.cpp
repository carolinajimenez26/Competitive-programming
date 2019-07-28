#include <bits/stdc++.h>
using namespace std;

const int INT_BITS = 32;

unsigned int leftRotate(unsigned int n, unsigned int d) {
   return (n << d)|(n >> (INT_BITS - d));
}

unsigned int rightRotate(unsigned int n, unsigned int d) {
   return (n >> d)|(n << (INT_BITS - d));
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while(t-- > 0){
    unsigned int n;
    cin >> n;
    vector<int> found(32);
    for (size_t i = 0; i < 32; i++) {
      int num = n & 31;
      found[num] = 1;
      n = rightRotate(n, 1);
    }

    int total_found = accumulate(found.begin(), found.end(), 0);
    cout << (total_found == 32 ? "yes" : "no") << endl;
  }
  return 0;
}
