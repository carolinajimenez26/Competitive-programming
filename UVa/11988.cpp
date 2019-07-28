#include <bits/stdc++.h>
using namespace std;

void print(list<string> l) {
  for (list<string>::iterator it = l.begin(); it != l.end(); it++)
    cout << *it;

  cout << '\n';
}

int main(void) {
  string line;
  bool at_beginning, at_end;
  while(getline(cin, line)) {
    at_beginning = false, at_end = true;
    list<string> mylist;
    for (int i = 0; i < line.length(); i++) {
      string tmp = "";
      while (i < line.length()) {
        if (line[i] == '[' or line[i] == ']') break;
        else tmp += line[i];
        i++;
      }
      if (at_beginning) mylist.push_front(tmp);
      else mylist.push_back(tmp);
      if (line[i] == '[') {
        at_beginning = true, at_end = false;
        continue;
      }
      if (line[i] == ']') {
        at_end = true, at_beginning = false;
        continue;
      }

    }
    print(mylist);
  }
  return 0;
}
