#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <unordered_map>
#define dbg(x) cout << #x << ": " << (x) << endl
using namespace std;

int memo[3000][3000];

class Solution {
    void print(const vector<vector<int>>& dp) {
        cout << "**********" << endl;
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[0].size(); j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << "**********" << endl;
    }

    int goFaster(const string &s1, const string &s2) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        // print(dp);
        for (int i = 1; i < dp.size(); i++) {
            dp[i][0] = int(s1[i - 1]) + dp[i - 1][0];
        }

        for (int j = 1; j < dp[0].size(); j++) {
            dp[0][j] = int(s2[j - 1]) + dp[0][j - 1];
        }
        // print(dp);
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[0].size(); j++) {
                if (s1[i - 1] != s2[j - 1]) {
                    dp[i][j] = min(
                                int(s1[i - 1]) + dp[i - 1][j],
                                int(s2[j - 1]) + dp[i][j - 1]
                               );
                } else {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        // print(dp);
        return dp.back().back();
    }

    int goMemo(const string &s1, const string &s2, int i, int j) {
        if (i <= -1 && j <= -1) {
            return 0;
        }
        if (memo[i + 1][j + 1] != -1) {
            return memo[i + 1][j + 1];
        }
        
        if (i == -1) {
            memo[i + 1][j + 1] = goMemo(s1, s2, i, j - 1) + int(s2[j]);
            return memo[i + 1][j + 1];
        }
        if (j == -1) {
            memo[i + 1][j + 1] = goMemo(s1, s2, i - 1, j) + int(s1[i]);
            return memo[i + 1][j + 1];
        }

        int ans = 30000000;
        if (s1[i] == s2[j]) {
            ans = goMemo(s1, s2, i - 1, j - 1);
        } else {
            ans = min(
                goMemo(s1, s2, i - 1, j) + int(s1[i]),
                goMemo(s1, s2, i, j - 1) + int(s2[j])
            );
        }
        memo[i +1][j+1] = ans;
        return ans;
    }

    int go(const string &s1, const string &s2, int i, int j) {
        if (i == -1 && j == -1) return 0;
        if (i == -1) {
            return go(s1, s2, i, j - 1) + int(s2[j]);
        }
        if (j == -1) {
            return go(s1, s2, i - 1, j) + int(s1[i]);
        }

        int ans = 10000000;
        if (s1[i] == s2[j]) {
            ans = go(s1, s2, i - 1, j - 1);
        } else {
            ans = min(
                go(s1, s2, i - 1, j) + int(s1[i]),
                go(s1, s2, i, j - 1) + int(s2[j])
            );
        }
        return ans;
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        memset(memo, -1, sizeof memo);
        return goMemo(s1, s2, s1.size() - 1, s2.size() - 1);
        // return goFaster(s1, s2);        
    }
};

int main() {
    Solution sol;
    // cout << sol.minimumDeleteSum("leet", "delete") << endl;
    cout << sol.minimumDeleteSum("delete", "leet") << endl;
    return 0;
}