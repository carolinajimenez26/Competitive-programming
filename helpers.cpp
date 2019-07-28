#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
#define INF numeric_limits<int>::max()

int tonum(char &s) {
  stringstream ss;
  ss << s;
  int out;
  ss >> out;
  return out;
}

vector<string> split(string &s) {
  stringstream ss;
  ss << s;
  vector<string> v;
  string tok;
  while (ss >> tok)
    v.push_back(tok);
  return v;
}

vector<string> split(string s, char tok) { // split a string by an  especified token
	istringstream ss(s);
  string token;
  vector<string> v;

  while(getline(ss, token, tok)) {
    v.push_back(token);
  }

  return v;
}

template <class T>
void print(T v) {
  for (auto i : v) cout << i << " ";
  cout << endl;
}

// Extracted from https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
void print2D(Node *root, int space, int COUNT) {
  // Base case
  if (root == NULL) return;
  // Increase distance between levels
  space += COUNT;

  // Process right child
  print2D(root->right, space, COUNT);

  cout << endl;
  for (int i = COUNT; i < space; i++) cout << " ";
  cout << root->data << endl;

  // Process left child
  print2D(root->left, space, COUNT);
}

int main(int argc, char const *argv[]) {
  // Accelerates the standar input
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i = MAX_INT, j = MIN_INT;
  cout << fixed << setprecision(6) << 30 << endl; // 30.000000
  return 0;
}
