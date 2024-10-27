#include <iostream>
#include <vector>
#define dbg(x) cout << #x << ": " << x << endl

using namespace std;
using int64 = long long int;

struct item {
  int64 key, prior, total_sum, node_freq;
  item * l, * r;
  item() { }
  item (int64 key, int64 prior) : key(key), prior(prior), l(NULL), r(NULL), total_sum(1), node_freq(1) { }
  item (int64 key) : item(key, rand()) {}
};
typedef item * pitem;

int64 total_sum (pitem t) {
  return t ? t->total_sum : 0;
}

void upd_total_sum (pitem t) {
  if (t)
    t->total_sum = t->node_freq + total_sum(t->l) + total_sum (t->r);
}

void split (pitem t, int64 key, pitem & l, pitem & r) {
  if (!t)
    l = r = NULL;
  else if (key < t->key)
    split (t->l, key, l, t->l),  r = t;
  else
    split (t->r, key, t->r, r),  l = t;

  upd_total_sum(l);
  upd_total_sum(r);
}

void merge (pitem & t, pitem l, pitem r) {
  if (!l || !r)
    t = l ? l : r;
  else if (l->prior > r->prior)
    merge (l->r, l->r, r),  t = l;
  else
    merge (r->l, l, r->l),  t = r;

  upd_total_sum(t);
}

pitem search(pitem it, int key) {
  if (it == nullptr || it->key == key) return it;
  return search(it->key < key ? it->r : it->l, key);
}

void insert (pitem & t, pitem it) {
  if (!t) {
    t = it;
    return;
  }
  if (it->key == t->key) {
    t->node_freq++;
    upd_total_sum(t);
    return;
  }
  // if (it->prior > t->prior) {
  //   split (t, it->key, it->l, it->r);
  //   t = it;
  // }
  // else {
  //   insert (it->key < t->key ? t->l : t->r, it);
  // }

  pitem node = search(t, it->key);
  if (node == nullptr) {
    pitem l, r;
    split(t, it->key, l, r);
    node->l = l;
    node->r = r;
    t = node;
  } else {
    node->node_freq++;
  }

  upd_total_sum(t);
}

void print2D(pitem root, int space = 0, int COUNT = 10) {
  // Base case
  if (root == nullptr) return;
  // Increase distance between levels
  space += COUNT;

  // Process right child
  print2D(root->r, space, COUNT);

  cout << endl;
  for (int i = COUNT; i < space; i++) cout << " ";
  cout << root->key << "x" << root->node_freq << "(" << root->prior << ")" << endl;

  // Process left child
  print2D(root->l, space, COUNT);
}

int64 SumAllLessThan(pitem root, int64 key) {
  if (root == nullptr) return 0;
  if (root->key == key) {
    return root->l != nullptr ? root->l->total_sum : 0;
  }
  if (root->key > key) {
    return SumAllLessThan(root->l, key);
  } else {
    return root->node_freq + (root->l != nullptr ? root->l->total_sum : 0) + SumAllLessThan(root->r, key);
  }
}

int64 GoodPairsTopics(const vector<int>& A, const vector<int>& B) {
  int64 result = 0;
  // Ai + Aj > Bi + Bj and i < j
  // that's the same as Ai - Bi > Bj - Aj
  pitem root = nullptr;
  for (int k = A.size() - 1; k >= 0; k--) {
    // print2D(root);
    int64 diff = A[k] - B[k];
    // dbg(diff);
    result += SumAllLessThan(root, diff);
    // dbg(result);
    insert(root, new item(B[k] - A[k]));
  }
  return result;
}

int main(void) {
  int n;
  cin >> n;
  vector<int> A(n), B(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> B[i];
  }
  cout << GoodPairsTopics(A, B) << endl;
  return 0;
}