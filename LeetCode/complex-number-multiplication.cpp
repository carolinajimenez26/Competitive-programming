#include <iostream>
#include <string>

using namespace std;

string complexNumberMultiply(string first, string second) {
  int a, b, c, d;
  sscanf(first.c_str(), "%d+%di", &a, &b);
  sscanf(second.c_str(), "%d+%di", &c, &d);
  int real = a * c - d * b;
  int img = a * d + c * b;
  string ans = "" + to_string(real) + "+" + to_string(img) + "i";
  return ans;
}

int main(void) {
  cout << complexNumberMultiply("100+2i","100+2i") << endl;
  return 0;
}
