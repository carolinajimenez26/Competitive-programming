#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class MyHashSet {
private:
  vector<bool> hash_table;
public:
  MyHashSet() {}
  
  void add(int key) {
    if (hash_table.size() <= key) {
      hash_table.resize(key * 2, false);
    }
    hash_table[key] = true;
  }
  
  void remove(int key) {
    if (key < hash_table.size()) {
      hash_table[key] = false;
    }
  }
  
  bool contains(int key) {
    if (key >= hash_table.size()) {
      return false;
    }
    return hash_table[key];
  }

  void Print() {
    for (int i = 0; i < hash_table.size(); i++) {
      if (hash_table[i]) cout << i << ", ";
    }
    cout << endl;
  }
};

int main(void) {
  MyHashSet* hash_table = new MyHashSet();
  hash_table->add(1);         
  hash_table->add(2);         
  assert(hash_table->contains(1)); // returns true
  assert(!hash_table->contains(3)); // returns false (not found)
  hash_table->add(2);          
  assert(hash_table->contains(2)); // returns true
  hash_table->remove(2);          
  assert(!hash_table->contains(2)); // returns false (already removed)

  return 0;
}