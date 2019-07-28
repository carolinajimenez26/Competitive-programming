#include <bits/stdc++.h>
using namespace std;

int main(void){
  int N, par[5], impar[5], par_cont = 0, impar_cont = 0, i = 0, j = 0, par_cont_aux = 0, cont = 0;
  bool flag = false;
  while (cont <= 15) {
    cin >> N;
    if (N % 2 == 0) {
      par[i] = N;
      par_cont++;
      i++;
      if (par_cont >= 5) {
        par_cont_aux++;
      }
    } else {
      impar[j] = N;
      impar_cont++;
      j++;
    }
    if (par_cont + impar_cont == 15) {
      for(int k = 0; k <= 5 - par_cont_aux; k++) cout << "impar[" << k << "] = " << impar[k] << endl;
      for(int k = 0; k < par_cont_aux - 1; k++) cout << "par[" << k << "] = " << par[k] << endl;
      break;
    }
    if (i == 5) {
      i = 0;
      for(int k = 0; k < 5; k++) cout << "par[" << k << "] = " << par[k] << endl;
    }
    if (j == 5) {
      j = 0;
      for(int k = 0; k < 5; k++) cout << "impar[" << k << "] = " << impar[k] << endl;
    }
    cont++;
  }
  return 0;
}
