// Binary Search Tree
#include<iostream>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
  Node* parent;

  Node () : data(), left(nullptr), right(nullptr), parent(nullptr) {};
  Node (int _data) : data(_data), left(nullptr), right(nullptr), parent(nullptr) {};
};

void insert(Node* n, Node* root, Node* current) {
  if (current == root && root->right == nullptr) {
    root->right = n;
    root->left = n;
    n->parent = root;
    return;
  }
  if (n->data == current->data) return;
  if (n->data < current->data) {
    if (current->left == nullptr) {
      current->left = n;
      n->parent = current;
    } else {
      insert(n, root, current->left);
    }
  } else {
    if (current->right == nullptr) {
      current->right = n;
      n->parent = current;
    } else {
      insert(n, root, current->right);
    }
  }
}

Node* find(int n, Node* current) {
  if (current == nullptr) return nullptr;
  if (current->data == n) return current;
  if (n < current->data) return find(n, current->left);
  else return find(n, current->right);
}

Node* getLeftLeaf(Node* n) {
  if (n->left == nullptr) return n;
  getLeftLeaf(n->left);
}

bool _delete(int data, Node* root) {
  Node* n = find(data, root->right);
  if (n == nullptr) return false;
  if (n->left == nullptr && n->right == nullptr) { // Is a leaf
    if (n->parent->left == n) {
      n->parent->left = nullptr;
    }
    if (n->parent->right == n) { // the root
      n->parent->right = nullptr;
    }
    delete n;
    return true;
  }
  if (n->left != nullptr && n->right == nullptr) { // If it only has a left child
    n->parent->left = n->left;
    n->left->parent = n->parent;
    delete n;
    return true;
  }
  if (n->left == nullptr && n->right != nullptr) { // If it only has a right child
    n->parent->right = n->right;
    n->right->parent = n->parent;
    delete n;
    return true;
  }
  // If it has a left and right child
  if (n->parent->left == n) { // replace the node for the parent
    n->parent->left = n->right;
    n->right->parent = n->parent;
  }
  if (n->parent->right == n) {
    n->parent->right = n->right;
    n->right->parent = n->parent;
  }
  Node* most_left = getLeftLeaf(n->right);
  most_left->left = n->left;
  n->left->parent = most_left;
  delete n;
  return true;
}

void deleteAll(Node* current) {
  if (current == nullptr) return;
  if (current->left == nullptr && current->right == nullptr) {
    if (current->parent->left == current) {
      current->parent->left = nullptr;
    }
    if (current->parent->right == current) { // the root
      current->parent->right = nullptr;
    }
    delete current;
    return;
  }
  deleteAll(current->left);
  deleteAll(current->right);
  deleteAll(current);
}

void print(Node* n) {
  if (n == nullptr) return;
  cout << n->data << endl;
  print(n->left);
  print(n->right);
}

void printParents(Node* n) {
  if (n == nullptr) return;
  cout << n->data << ": " << n->parent->data << endl;
  printParents(n->left);
  printParents(n->right);
}

int main(void) {
  Node* root = new Node(0);
  insert(new Node(8), root, root);
  insert(new Node(3), root, root);
  insert(new Node(5), root, root);
  insert(new Node(1), root, root);
  insert(new Node(4), root, root);
  insert(new Node(7), root, root);
  insert(new Node(9), root, root);
  print(root->right);
  printParents(root->right);

  // int element = 3;
  // Node* x = find(element, root->right);
  // if (x != nullptr) {
  //   cout << "The element " << element << " is in the BST" << endl;
  //   cout << "Its parent is " << x->parent->data << endl;
  // } else {
  //   cout << "The element " << element << " is not in the BST" << endl;
  // }
  _delete(8, root);
  print(root->right);
  printParents(root->right);

  // Free Memory
  deleteAll(root->right);
  delete root;
  return 0;
}
