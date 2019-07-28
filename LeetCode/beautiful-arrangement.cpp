#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void print(const vector<int>& v) {
        for (auto e : v) cout << e << " ";
        cout << endl;
    }

    void print(const vector<vector<int>>& v) {
        for (int i = 0; i < v.size(); i++) {
            cout << (i + 1) << " -> ";
            print(v[i]);
        }
        cout << endl;
    }

    vector<int> addValidPositions(int n, int maxN) {
        vector<int> result;
        for (int i = 1; i <= maxN; i++) {
            if ((n % i == 0) || (i % n == 0)) {
                result.push_back(i - 1);
            }
        }
        return result;
    }

    void tryAll(vector<int>& v, int n, int maxN, int& result, 
                const vector<vector<int>>& positions) {
        if (n > maxN) {
            result++;
            return;
        }
        for (auto e : positions[n - 1]) {
            if (v[e] != -1) continue;
            v[e] = n;
            tryAll(v, n + 1, maxN, result, positions);
            v[e] = -1;
        }
    }

public:
    int countArrangement(int N) {
        int result = 0;
        if (N == 0) return result;
        vector<vector<int>> positions(N);

        for (int i = 1; i <= N; i++) {
            positions[i - 1] = addValidPositions(i, N);
        }
        // print(positions);
        vector<int> v(N, -1);
        tryAll(v, 1, N, result, positions);
        return result;
    }
};

int main(void) {
    Solution sol;
    cout << sol.countArrangement(4) << endl;
    return 0;
}