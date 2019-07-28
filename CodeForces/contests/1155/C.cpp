#include <iostream>
#include <vector>
#define ulli long long int

using namespace std;

ulli gcd(ulli a, ulli b) {
    if (b > a) swap(a, b);
    while (b > 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

pair<ulli, ulli> AlarmSettings(vector<ulli>& x,
                             vector<ulli>& p) {
    
    ulli common_gcd = 0;
    for (int i = 1; i < x.size(); i++) {
        common_gcd = gcd(common_gcd, x[i] - x[i - 1]);
    }

    for (int i = 0; i < p.size(); i++) {
        if ((common_gcd % p[i]) == 0) {
            return {x[0], i + 1};
        }
    }
    return {-1, -1};
}

int main(void) {
    int n, m;
    cin >> n >> m;
    vector<ulli> x(n);
    vector<ulli> p(m);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }

    pair<ulli, ulli> result = AlarmSettings(x, p);

    if (result.first == -1) cout << "NO" << endl;
    else cout << "YES" << endl << result.first << " " << result.second << endl;
}