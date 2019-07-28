#include <bits/stdc++.h>

#define dbg(x) cout << #x << ": " << (x) << endl

using namespace std;

class Solution {
    vector<int> Remainders(int n) {
        vector<int> ans;
        while (n != 0) {
            ans.push_back(n % -2);
            n /= -2;
        }
        return ans;
    }

public:
    string baseNeg2(int N) {
        if (N == 0) return "0";
        vector<int> remainders = Remainders(N);
        int carry = 0;
        string ans;
        for (int i = 0; i < remainders.size() || carry; i++) {
            int cur = carry;
            if (i < remainders.size()) {
                cur += remainders[i];
            }
            ans.push_back('0' + (cur & 1));
            if (cur == 0 || cur == 1) carry = 0;
            if (cur < 0) carry = 1;
            if (cur == 2) carry = -1;
        }
        while (ans.size() > 1 && ans.back() == '0') {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;       
    }
};

int main(int argc, char **argv) {
    Solution sol;
    for (int i = 1; i < argc; i++) {
        cout << sol.baseNeg2(atoi(argv[i])) << endl;
    }
    return 0;
}