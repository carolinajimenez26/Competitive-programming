#include <bits/stdc++.h>
using namespace std;

vector<string> split(string &s){
  stringstream ss;
  ss << s;

  vector<string> v;
  string tok;
  while(ss >> tok){
    v.push_back(tok);
  }
  return v;
}

int main(void){
  string line;
  vector<string> v;
  int sum = 0, e = 0;
  while (getline(cin,line)) {
    v = split(line);
    if (v.size() == 1) {
      for(int i = 2; i >= 0; i--) {
        if (line[i] == '*') sum += pow(2,2-i);
      }
    } else {
      cout << sum << endl;
      sum = 0;
    }
  }
  return 0;
}
