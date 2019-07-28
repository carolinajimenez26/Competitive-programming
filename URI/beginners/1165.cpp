#include <bits/stdc++.h>
using namespace std;
#define MAX 10000005
bool bs[MAX];

void sieve(){
  bs[0] = bs[1] = 0; //no son primos
  for(long long i = 2; i < MAX; i++){
    if(bs[i]){//si no ha sido tachado como primo
      for(long long j = i*i; j < MAX; j += i)
        bs[j] = 0; //se tachan todos sus múltiplos
    }
  }
}

int main(void){
  long long a;
  int N;
  memset(bs,1, sizeof bs);//inicialmente decimos que todos son primos
  sieve();
  cin >> N;
  while (N--) {
    cin >> a;
    if(bs[a]) cout<< a <<" eh primo"<<endl;
    else cout<< a <<" nao eh primo"<<endl;
  }
  return 0;
}
