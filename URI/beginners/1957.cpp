#include <bits/stdc++.h>
using namespace std;

int main(void){
  unsigned int N;
  cin >> N;
  stringstream ss;
  string ans;
  ss << hex << N;
  ans = ss.str();
  transform(ans.begin(), ans.end(), ans.begin(), ::toupper);
  cout << ans << endl;
  return 0;
}
