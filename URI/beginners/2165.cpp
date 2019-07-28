#include <bits/stdc++.h>
using namespace std;

int main(void){
  string txt;
  getline(cin,txt);
  if (txt.length() <= 140) cout << "TWEET" << endl;
  else cout << "MUTE" << endl;
  return 0;
}
