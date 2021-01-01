#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

struct Element {
  int val;
  int pos;
};

struct comp {
  bool operator() (const Element& a, const Element& b) const {return a.pos < b.pos;}
};

class FirstUnique {
private:
  int idx;
  set<Element, comp> elems;
  unordered_map<int, Element> elems_values;
public:
  FirstUnique(vector<int>& nums) {
    idx = 0;
    for (int i = 0; i < nums.size(); i++) {
      add(nums[i]);
    }
  }

  int showFirstUnique() {
    return elems.empty() ? -1 : (*elems.begin()).val;
  }

  void add(int value) {
    if (elems_values.count(value) == 0) { // uniques
      Element e{value, idx};
      elems.insert(e);
      elems_values[value] = e;
      idx++;
    } else { // not unique anymore
      elems.erase(elems_values[value]);
      // elems_values.erase(value);
    }
  }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
int main(void) {
  return 0;
}