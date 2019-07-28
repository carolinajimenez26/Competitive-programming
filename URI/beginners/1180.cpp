#include <bits/stdc++.h>
using namespace std;

int tonum(string &s){
  stringstream ss;
  ss << s;
  int out;
  ss >> out;
  return out;
}

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
  int menor = numeric_limits<int>::max(), pos, l;
  string line, limit;
  getline(cin,limit);
  getline(cin, line);
  vector<string> splitted = split(line);
  l = tonum(limit);
  for(int i = 0; i < l; i++){
    if (tonum(splitted[i]) < menor){
      menor = tonum(splitted[i]);
      pos = i;
    }
  }
  cout << "Menor valor: " << menor << endl;
  cout << "Posicao: " << pos << endl;
  return 0;
}
