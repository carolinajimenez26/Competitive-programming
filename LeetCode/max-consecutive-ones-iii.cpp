#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int countOnes(const vector<int>& A, int& j) {
        int ones = 0;
        while (j < A.size() && A[j] == 1) {
            ones++;
            j++;
        }
        return ones;
    }

    int longestOnes(vector<int>& A) {
        int result = 0, ones = 0;
        for (int i = 0, j = 0; i < A.size();) {
            if (A[i] == 1) {
                j = i;
                ones = countOnes(A, j);
                if (ones > result) {
                    result = ones;
                }
                i = j;
                ones = 0;
            } else {
                i++;
            }
        }
        return result;
    }
public:
    int longestOnes(vector<int>& A, int K) {
        if (A.size() == 0) return 0;
        if (A.size() == 1) return 1;
        if (K == 0) return longestOnes(A);
        int i = 0, j = 1, Ks = 0, max_count = 0;
        if (A[0] == 0) Ks++;
        while (i < A.size() && j < A.size()) {
            while (j < A.size() && (Ks < K || A[j])) {
                if (A[j] == 0) Ks++;
                j++;
            }
            if (j - i + 1 > max_count) max_count = j - i + 1;
            if (A[i] == 0) Ks--;
            i++;
        }
        return max_count - 1;
    }
};

int main(void) {
    Solution sol;
    vector<int> input = {1,0,0,0,1,0,0,0,1,0,1,1,0,0,0,1,1};
    sol.longestOnes(input, 1);
    return 0;
}