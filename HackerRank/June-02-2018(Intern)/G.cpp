#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
#define INF numeric_limits<int>::max()


int repart(int candies, int friends) {
    int aux = candies, solv = 0;
    if(candies == 0) return 1;
    if(friends == 0) return 0;

    for(int i = 1; i <= friends; i++){

      for(int j = 0; j < aux; j++){

        candies -= 1;
        solv += repart(candies, friends - i);


      }

      candies = aux;

    }
    return solv;
}


int main(void) {

  int T, D, K;

  cin>>T;

  while(T--){

    cin>> D >> K;
    int r = repart(D, K);

    cout<< r << endl;
  }
  return 0;
}
