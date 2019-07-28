#include <bits/stdc++.h>
using namespace std;

int compare (const void * a, const void * b){
  return ( *(double*)a - *(double*)b );
}

int main(void){
  double all[3];
  cin >> all[0] >> all[1] >> all[2];
  qsort(all, 3, sizeof(double), compare);
  if (all[2] >= all[1] + all[0]) cout << "NAO FORMA TRIANGULO" << endl;
  else{
    if (all[2]*all[2] == all[1]*all[1] + all[0]*all[0]) cout << "TRIANGULO RETANGULO" << endl;
    if (all[2]*all[2] > all[1]*all[1] + all[0]*all[0]) cout << "TRIANGULO OBTUSANGULO" << endl;
    if (all[2]*all[2] < all[1]*all[1] + all[0]*all[0]) cout << "TRIANGULO ACUTANGULO" << endl;
    if (all[2] == all[1] && all[1] == all[0]) cout << "TRIANGULO EQUILATERO" << endl;
    else if (all[2] == all[1] || all[2] == all[0] || all[0] == all[1]) cout << "TRIANGULO ISOSCELES" << endl;
  }
  return 0;
}
