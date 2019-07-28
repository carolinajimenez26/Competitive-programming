#include <bits/stdc++.h>
using namespace std;

void print(char a[], int size) {
  for (int i = 0; i < size; i++) cout << a[i];
  cout << endl;
}

int main (void) {
  string in;
  bool flag;
  while (cin >> in) {
    if (in == "#") break;
    flag = false;
    char array[in.length()];
    for (int i = 0; i < in.length(); i++) array[i] = in[i];
    if (next_permutation(array, array + in.length())) print(array, in.length());
    else cout << "No Successor" << endl;
  }
  return 0;
}
