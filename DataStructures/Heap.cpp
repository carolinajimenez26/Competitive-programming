#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

// For a max heap you should invert the logic
class MinHeap {
private:
  vector<int> nodes;

  bool IsValid(int idx) {
    return idx >= 0 && idx < nodes.size();
  }

  void BublbeUp(int idx) {
    int parent = (idx - 1) / 2;
    if (parent < 0 || nodes[parent] <= nodes[idx]) return;
    swap(nodes[parent], nodes[idx]);
    BublbeUp(parent);
  }

  void BublbeDown(int idx) {
    int left_child = idx * 2 + 1;
    int right_child = idx * 2 + 2;
    int smaller = idx, smaller_val = nodes[idx];
    if (IsValid(left_child) && smaller_val > nodes[left_child]) {
      smaller_val = nodes[left_child];
      smaller = left_child;
    }
    if (IsValid(right_child) && smaller_val > nodes[right_child]) {
      smaller_val = nodes[right_child];
      smaller = right_child;
    }
    if (smaller != idx) {
      swap(nodes[idx], nodes[smaller]);
      BublbeDown(smaller);
    }
  }

public:
  void Pop() {
    int size = nodes.size();
    if (nodes.empty()) {
      cout << "Error, the heap is empty" << endl;
      assert(false);
    }
    swap(nodes[0], nodes[size - 1]);
    nodes.pop_back();
    if (!nodes.empty()) BublbeDown(0);
  }

  int Front() {
    if (nodes.empty()) {
      cout << "Error, the heap is empty" << endl;
      assert(false);
    }
    return nodes.front();
  }

  void Insert(int x) { // O (log n)
    nodes.push_back(x); // O (1)
    BublbeUp(nodes.size() - 1); // O (log n)
  }
};

int main(void) {
  MinHeap mh;
  mh.Insert(10);
  assert(mh.Front() == 10);
  mh.Insert(5);
  assert(mh.Front() == 5);
  mh.Insert(7);
  assert(mh.Front() == 5);
  mh.Insert(1);
  assert(mh.Front() == 1);
  mh.Pop(); // removes 1
  assert(mh.Front() == 5);
  mh.Pop(); // removes 5
  assert(mh.Front() == 7);
  mh.Pop(); // removes 7
  assert(mh.Front() == 10);
  mh.Pop(); // removes 10
  return 0;
}