#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int solver(const vector<int>& A, int idx) {
        if (idx >= A.size()) {
            return 0;
        }
        if (memo[idx] != -1) {
            return memo[idx];
        }
        int best = A[idx], greater = A[idx];
        for (int i = 0; i < k && (idx + i) < A.size(); i++) {
            greater = max(greater, A[idx + i]);
            int current = greater * (i + 1);
            best = max(best, current + solver(A, idx + i + 1));
        }
        memo[idx] = best;
        return best;
    }

    int maxSumAfterPartitioning(vector<int>& A, int K) {
        k = K;
        memo.assign(A.size(), -1);
        return solver(A, 0);
    }
private:
    int k;
    vector<int> memo;
};

int main(void) {
    vector<int> input = {2,5,10};
    Solution sol;
    cout << sol.maxSumAfterPartitioning(input, 2) << endl;
    return 0;
}