#include <bits/stdc++.h>
using namespace std;

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main(void){
  int A, B, C;
  cin >> A >> B >> C;
  int D[] = {A, B, C};
  qsort(D, 3, sizeof(int), cmpfunc);// ascendent order
  for(int i = 0; i < 3; i++) cout << D[i] << endl;
  cout << endl << A << endl << B << endl << C << endl;
  return 0;
}
