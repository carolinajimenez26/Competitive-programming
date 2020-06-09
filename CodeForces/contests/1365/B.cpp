#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Element {
  int val;
  bool type;

  bool operator<(const Element& other) const {
    return val < other.val;
  }

  bool operator==(const Element& other) const {
    return val == other.val && type == other.type;
  }
};

int main(void) {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<Element> elements(n);
    int ones = 0;
    for (int i = 0; i < n; i++) {
      int val;
      cin >> val;
      elements[i].val = val;
    }
    for (int i = 0; i < n; i++) {
      bool type;
      cin >> type;
      elements[i].type = type;
      if (type) {
        ones++;
      }
    }
    vector<Element> copy = elements;
    sort(copy.begin(), copy.end());
    bool possible = false;
    if (ones == 0) {
      possible |= (copy == elements);
    } else if (ones == n) {
      possible |= (copy == elements);
    } else {
      possible |= (ones >= 1);
    }
    cout << (possible ? "Yes" : "No") << endl;
  }
  return 0;
}