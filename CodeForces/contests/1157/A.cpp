#include <iostream>
#include <set>
#define dbg(x) cout << #x << ": " << (x) << endl

using namespace std;

long long int f(long long int x) {
    x += 1;
    while (x % 10 == 0) {
        x /= 10;
    }
    return x;
}

long long int reachables(long long int n) {
    set<long long int> result;
    result.insert(n);
    while (true) {
        n = f(n);
        if (result.count(n)) break;
        result.insert(n);
        // dbg(n);
    }
    return result.size();
}

int main(void) {
    int n;
    cin >> n;
    cout << reachables(n) << endl;
    return 0;
}