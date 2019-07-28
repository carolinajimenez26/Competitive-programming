//Sorted List Matching Problem
#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
#define endl '\n'

void print(vector<string> X) {
  for (int i = 0; i < X.size(); i++) {
    cout << X[i] << " ";
  }
  cout << endl;
}

vector<string> SLM(string A[], string B[], int lenA, int lenB) {
  vector<string> ans;
  int i = 0, j = 0;
  while (true) {
    if (i >= lenA or j >= lenB) break;
    if (A[i] == B[j]) {
      ans.push_back(A[i]);
      j++; i++;
    }
    if (i >= lenA or j >= lenB) break;
    if (A[i][0] < B[j][0]) { //Analize firsts characters
      i++; // continue searching on the second list
    } else {
      j++;
    }
  }
  return ans;
}

int main(void) {
  string A[] = {"Adams","Bell","Davis","Harding","Jenkins","Lincoln","Simpson","Zoeller"};
  string B[] = {"Boston","Davis","Duncan","Francis","Gamble","Harding","Mason","Simpson"};
  int lenA = sizeof(A)/sizeof(*A), lenB = sizeof(B)/sizeof(*B);
  vector<string> C = SLM(A,B,lenA,lenB);
  print(C);
  return 0;
}
