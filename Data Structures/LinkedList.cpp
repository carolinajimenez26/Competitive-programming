#include<iostream>
using namespace std;

struct Node {
  int data;
  Node* next;

  Node () : data(), next(nullptr) {};
  Node (int _data) : data(_data), next(nullptr) {};
  Node (int _data, Node* _next) : data(_data), next(_next) {};
};

void printList(Node* n) {
  while (n != nullptr) {
     cout << n->data << " -> ";
     n = n->next;
  }
  cout << endl;
}

// push element in a position called index
void push(int index, Node* n, Node* head) {
  if (index == 0) { // push in the beginning
    if (head->next == nullptr) {
      head->next = n;
    } else {
      Node* first = head->next;
      head->next = n;
      n->next = first;
    }
  } else { // if index is > than the amount of elements in the list, it push at the end
    Node* prev = head;
    Node* current = prev->next;
    for (int i = 0; i < index; i++) {
      if (current == nullptr) { // prev is the last element
        break;
      }
      prev = current;
      current = current->next;
    }
    if (current == nullptr) {
      prev->next = n;
    } else {
      n->next = current;
      prev->next = n;
    }
  }
}

void append(Node* n, Node* head) { // Put Node n in the end of the list
  if (head->next == nullptr) {
    head->next = n;
  } else {
    Node* current = head->next;
    while (current->next != nullptr) { // Find the last element in the list
      current = current->next;
    }
    current->next = n;
  }
}

void deleteByIndex(int index, Node* head) {
  Node* prev = head;
  Node* current = prev->next;
  for (int i = 0; i < index; i++) {
    if (current->next == nullptr) { // current is the last element
      break;
    }
    prev = current;
    current = current->next;
  }
  if (current->next == nullptr) {
    prev->next = nullptr;
    delete current;
  } else {
    prev->next = current->next;
    delete current;
  }
}

void deleteByData(int data, Node* head) {
  Node* prev = head;
  Node* current = head->next;
  while (current != nullptr) {
    if (current->data == data) break;
    prev = current;
    current = current->next;
  }
  if (current != nullptr) { // We have something to delete
    prev->next = current->next;
    delete current;
  }
}

int getSize(Node* head) {
  Node* current = head->next;
  int size = 0;
  while (current != nullptr) {
    current = current->next;
    size++;
  }
  return size;
}

int main(void) {
  Node* head = new Node(); // Always points to the first element of the list
  push(0, new Node(5), head);
  push(0, new Node(4), head);
  printList(head->next);
  push(1, new Node(10), head);
  printList(head->next);
  push(100, new Node(2), head);
  printList(head->next);
  push(2, new Node(1), head);
  printList(head->next);
  append(new Node(7), head);
  printList(head->next);
  deleteByIndex(0, head);
  deleteByIndex(2, head);
  deleteByIndex(100, head);
  deleteByIndex(2, head);
  printList(head->next);
  deleteByData(10, head);
  deleteByData(100, head);
  printList(head->next);
  deleteByData(1, head);
  printList(head->next);
  append(new Node(8), head);
  append(new Node(3), head);
  printList(head->next);
  int size = getSize(head);
  cout << "size: " << size << endl;
  for (int i = 0; i < size; i++) {
    deleteByIndex(i, head);
  }
  printList(head->next);
  delete head;
  return 0;
}
