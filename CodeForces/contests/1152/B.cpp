#include <iostream>
#include <vector>
#include <cmath>
#define dbg(x) cout << #x << ": " << (x) << endl

using namespace std;

void print(const vector<int>& v) {
    for (auto e : v) {
        cout << e << " ";
    }
    cout << endl;
}

void doOp(int& x, bool op, vector<int>& v) {
    if (op) {
        int n = log2(x) + 1;
        x = x ^ ((int)pow(2, n) - 1);
        v.push_back(n);
    } else {
        x += 1;
    }
}

bool perfect(int x) {
    int bits = log2(x) + 1;
    int n = 1 << bits;
    n -= 1;
    return ((x & n) == n);
}

int catFurrierTransform(int x, vector<int>& n) {
    int ops = 0;
    bool op = true; // op A is 1, and op B is 0
    while (!perfect(x)) {
        doOp(x, op, n);
        ops++;
        op = !op;
    }
    return ops;
}

int main(void) {
    int x;
    cin >> x;
    vector<int> n;
    int result = catFurrierTransform(x, n);
    cout << result << endl;
    if (result != 0) print(n);
    return 0;
}