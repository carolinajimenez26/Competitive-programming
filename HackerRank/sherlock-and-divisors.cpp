#include <iostream>
#include <math.h>
#define dbg(x) cout << #x << ": " << x << endl

using namespace std;
  
int countDivisors(int n) { 
    int count = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) { 
            if (n / i == i) {
                if (i % 2 == 0) count++;
            }
            else {
                if (i % 2 == 0) count++;
                if (n / i % 2 == 0) count++;
            }
        } 
    }
    return count; 
} 
  
int main(void) {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << countDivisors(n) << endl;
    } 
    return 0; 
} 
