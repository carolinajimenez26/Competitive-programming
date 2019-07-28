#include <bits/stdc++.h>
using namespace std;
int N[20];

void change(){
  int tmp;
  for(int i = 0; i < 10; i++){
    tmp = N[19 - i]; //last
    N[19 - i] = N[i];
    //cout << "N[" << 20 - i << "] = " << N[i] << endl;
    N[i] = tmp; //first
    //cout << "N[" << i << "] = " << tmp << endl;
  }
  //cout << "----------------" << endl;
}

int main(void){
  for(int i = 0; i < 20; i++) cin >> N[i];
  change();
  for(int i = 0; i < 20; i++) cout << "N[" << i << "] = " << N[i] << endl;
  return 0;
}
