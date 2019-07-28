#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl

void print(vector<int> numbers) {
  cout << "--------" << endl;
  for (int i = 0; i < numbers.size(); i++) {
    cout << numbers[i] << " ";
  }
  cout << endl;
}

int main(void) {

  int T, N, num, mayor = numeric_limits<int>::min();
  cin >> T;
  while(T --) {
    cin >> N;
    // int numbers[N];
    vector<int> numbers;
    for(int i = 0; i < N; i++) {
      cin >> num;
      numbers.push_back(num);
    }
    sort(numbers.begin(), numbers.end());
    //print(numbers);
    bool flag = true;
    int i = 1;
    while (flag) {
      if (numbers[N-i] != numbers[N-(i+1)]){
        int aux = numbers[N-i] - numbers[N-(i+1)];
        numbers.pop_back();
        numbers.push_back(aux);
        sort(numbers.begin(), numbers.end());
        //print(numbers);
      }
      else i++;
      int cont = 0;
      if(numbers[N-1] == numbers[0])
      for(int i = 0; i < N; i++){
          cont ++;
          if (cont == N){
             cout << numbers[0] << endl;
             flag = false;
           }
      }
  }

  }
  return 0;
}
