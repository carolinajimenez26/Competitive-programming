#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define dbg(x) cout << #x << ": " << x << endl;

int maxFlowers(int A[], int size) {
  //cout << "-----" << endl;
  int max = 0, sum = 0, start = 0, end = 0, i = 0;
  set<int> s;
  for (int j = 0; j < size; j++) {
    //cout << "A[" << j << "] = " << A[j] << endl;
    if (!s.count(A[j])) { // si no está en el conjunto
      s.insert(A[j]);
      if (max < s.size()) {
        max = s.size();
        end = j;
      }
    } else { // ya existe
      while (true) { // busca desde donde empezar a contar
          if (A[i] == A[j]) { // si lo encuentra
            //dbg(i);
            i++; // empieza a contar desde uno más allá
            //cout << "Cuente desde el numero : " << A[i] << " , pos : " << i << endl;
            j = i - 1;
            break;
          }
          i++;
      }
      s.clear(); // saca los elementos del conjunto
    }
  }
  return max;
}

int main(void) {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int t, c, ci, sz, vl;
  cin >> t;
  while(t--){
    cin >> c;
    int A[c];
    for(int i = 0; i < c; i++){
      cin >> A[i];
    }
    cout << maxFlowers(A,c) << endl;
  }
  return 0;
}
