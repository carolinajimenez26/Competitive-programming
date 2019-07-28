#include <bits/stdc++.h>
using namespace std;

int compare (const void * a, const void * b){
  return ( *(double*)a - *(double*)b );
}

int main(void){
  int a, b, sum = 0, tmp;
  cin >> a >> b;
  if (a > b) {
    tmp = a;
    a = b;
    b = tmp;
  }
  a++;
  for(int i = a; i < b; i++){
    if(i % 2 != 0) sum += i;
  }
  cout << sum << endl;
  return 0;
}
