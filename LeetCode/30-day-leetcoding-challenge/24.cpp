#include <iostream>
#include <vector>
#include <unordered_map>
#define dbg(x) cout << #x << ": " << x << endl
using namespace std;

struct Element {
  int val, pos;
};

class LRUCache {
private:
  vector<int> v;
  int left, right;
  vector<bool> hole;
  unordered_map<int, Element> availables;
  int curr_capacity, capacity;

  void MoveLeft() {
    int new_left = left;
    while (hole[left]) {
      left++;
    }
  }

  void AddToLast(int key) {
    v.push_back(key);
    hole.push_back(false);
    right++;
  }

  void MoveToLast(int pos) {
    AddToLast(v[pos]);
    hole[pos] = true;
    if (pos == left) {
      MoveLeft();
    }
  }

  void printp() {
    for (int i = 0; i < v.size(); i++) {
      if (hole[i]) cout << "x";
      else cout << v[i];
      cout << " ";
    }
    cout << endl;
    dbg(left); dbg(right);dbg(curr_capacity);dbg(capacity);
    for (auto e : availables) {
      cout << e.first << " -> " << "(" << e.second.val << ", " << e.second.pos
           << ")" << endl;
    }
  }
public:
  LRUCache(int _capacity) {
    capacity = _capacity;
    left = curr_capacity = 0;
    right = -1;
  }

  int get(int key) {
    if (availables.count(key) == 0) {
      return -1;
    }
    int curr_pos = availables[key].pos;
    int val = availables[key].val;
    if (curr_pos == right) {
      return val;
    }
    MoveToLast(curr_pos);
    availables[key].pos = right;
    return val;
  }

  void put(int key, int value) {
    if (availables.count(key) > 0) {
      availables[key].val = value;
      MoveToLast(availables[key].pos);
      availables[key].pos = right;
      return;
    }
    if (curr_capacity == capacity) {
      // we have to remove the less used element
      availables.erase(v[left]);
      hole[left] = true;
      MoveLeft();
      AddToLast(key);
      availables[key] = {value, right};
    } else {
      AddToLast(key);
      availables[key] = {value, right};
      curr_capacity++;
    }
  }

  void print() {
    dbg("---------");
    printp();
    dbg("---------");
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
int main(void) {
  LRUCache* obj = new LRUCache(4);
  obj->put(1,1);
  obj->put(2,2);
  obj->print();
  dbg(obj->get(3));
  dbg(obj->get(1));
  obj->print();
  obj->put(3,3);
  obj->print();
  dbg(obj->get(3));
  obj->print();
  obj->put(4,4);
  obj->print();
  dbg(obj->get(3));
  obj->print();
  dbg(obj->get(2));
  obj->print();
  dbg(obj->get(4));
  obj->print();
  dbg(obj->get(5));
  obj->print();
  obj->put(5,5);
  obj->print();
  return 0;
}
