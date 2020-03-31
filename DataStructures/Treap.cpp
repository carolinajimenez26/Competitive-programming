// taken from https://cp-algorithms.com/data_structures/treap.html#toc-tgt-5
#include <iostream>

using namespace std;

struct item {
  int key, prior;
  item * l, * r;
  item() { }
  item (int key, int prior) : key(key), prior(prior), l(NULL), r(NULL) { }
};
typedef item * pitem;

void split (pitem t, int key, pitem & l, pitem & r) {
  if (!t)
    l = r = NULL;
  else if (key < t->key)
    split (t->l, key, l, t->l),  r = t;
  else
    split (t->r, key, t->r, r),  l = t;
}

void insert (pitem & t, pitem it) {
  if (!t)
    t = it;
  else if (it->prior > t->prior)
    split (t, it->key, it->l, it->r),  t = it;
  else
    insert (it->key < t->key ? t->l : t->r, it);
}

void merge (pitem & t, pitem l, pitem r) {
  if (!l || !r)
    t = l ? l : r;
  else if (l->prior > r->prior)
    merge (l->r, l->r, r),  t = l;
  else
    merge (r->l, l, r->l),  t = r;
}

void erase (pitem & t, int key) {
  if (t->key == key)
    merge (t, t->l, t->r);
  else
    erase (key < t->key ? t->l : t->r, key);
}

pitem unite (pitem l, pitem r) {
  if (!l || !r)  return l ? l : r;
  if (l->prior < r->prior)  swap (l, r);
  pitem lt, rt;
  split (r, l->key, lt, rt);
  l->l = unite (l->l, lt);
  l->r = unite (l->r, rt);
  return l;
}

// Extracted from https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
void print2D(pitem root, int space = 0, int COUNT = 10) {
  // Base case
  if (root == nullptr) return;
  // Increase distance between levels
  space += COUNT;

  // Process right child
  print2D(root->r, space, COUNT);

  cout << endl;
  for (int i = COUNT; i < space; i++) cout << " ";
  cout << root->key << "(" << root->prior << ")" << endl;

  // Process left child
  print2D(root->l, space, COUNT);
}

int main(void) {
  int keys[] = {3, 1, 4, 2, 9, 5, 7, 8, 6};
  pitem root = nullptr;
  for (auto key : keys) {
    int prior = rand() % 100;
    pitem node = new item(key, prior);
    insert(root, node);
  }
  cout << "---------------" << endl;
  print2D(root);
  cout << "---------------" << endl;

  pitem l = nullptr;
  pitem r = nullptr;
  split(root, 5, l, r);
  cout << "-------left-------" << endl;
  print2D(l);
  cout << "-------right-------" << endl;
  print2D(r);
  cout << "-------root-------" << endl;
  print2D(root);

  merge(root, l, r);
  cout << "-------After merging l and r-------" << endl;
  print2D(root);

  erase(root, 5);
  cout << "-------After removing 5-------" << endl;
  print2D(root);

  return 0;
}