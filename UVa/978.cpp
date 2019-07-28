#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


struct compare {
  bool operator() (const int& lhs, const int& rhs) const
  { return lhs > rhs; }
};

void print(multiset<int, compare> m) {
  multiset<int>::iterator it;
  for (it = m.begin(); it != m.end(); ++it)
    cout << *it << endl;
  // cout << endl;
}

void erase(multiset<int, compare> &ms, multiset<int>::iterator &it) {
  multiset<int>::iterator tmp;
  tmp = it;
  ++it;
  ms.erase(tmp);
}

void insert(multiset<int, compare> &ms, vector<int> v) {
  multiset<int>::iterator it;
  for(auto e : v) {
    it = ms.insert(e);
  }
}

void battle(multiset<int, compare> greens, multiset<int, compare> blues, int battles) {
  int size;
  multiset<int>::iterator it_blue, it_green;
  while (true) {
    vector<int> v_green, v_blue;
    size = min(greens.size(), blues.size());
    if (size == 0) break;
    // dbg(size);
    it_green = greens.begin();
    it_blue = blues.begin();
    int i = 0;
    for (int j = 0; j < size and i < battles; j++, i++) {

      if (*it_green == *it_blue) {
        erase(greens, it_green);
        erase(blues, it_blue);
      } else if (*it_green > *it_blue) {
        v_green.push_back(*it_green - *it_blue);
        erase(greens, it_green);
        erase(blues, it_blue);
      } else {
        v_blue.push_back(*it_blue - *it_green);
        erase(blues, it_blue);
        erase(greens, it_green);
      }
    }
    insert(greens, v_green);
    insert(blues, v_blue);
    if (min(greens.size(), blues.size()) == 0) break;

  }

  if (greens.size() > blues.size()) {
    cout << "green wins" << endl;
    print(greens);
  } else if (greens.size() < blues.size()) {
    cout << "blue wins" << endl;
    print(blues);
  } else cout << "green and blue died" << endl;
}

int main(int argc, char const *argv[]) {
  int tc, battles, sg, sb, x;
  cin >> tc;
  while (tc--) {
    multiset<int, compare> greens;
    multiset<int, compare> blues;
    cin >> battles >> sg >> sb;
    for (int i = 0; i < sg; i++) {
      cin >> x;
      greens.insert(x);
    }
    for (int i = 0; i < sb; i++) {
      cin >> x;
      blues.insert(x);
    }
    // print(greens);
    // print(blues);
    battle(greens, blues, battles);
    if (tc != 0) cout << endl;
  }
  return 0;
}
