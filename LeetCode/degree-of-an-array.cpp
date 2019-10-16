#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int GetDegree(const vector<int>& nums) {
        unordered_map<int, int> freqs;
        int greater = 0;
        for (auto e : nums) {
            freqs[e]++;
            if (greater < freqs[e]) {
                greater = freqs[e];
            }
        }
        return greater;
    }

    void Move(map<int, set<int>>& degrees, int from_degree, int to_degree, int target) {
        // move target from from_degree to to_degree of degrees
        degrees[from_degree].erase(target);
        if (from_degree != 0 && degrees[from_degree].size() == 0) {
            degrees.erase(from_degree);
        }
        degrees[to_degree].insert(target);
    }

    void Increment(unordered_map<int, int>& elem_freqs, int key, int val) {
        // Increment value val of key key in elem_freqs
        elem_freqs[key] += val;
    }

    int findShortestSubArray(vector<int>& nums) {
        int degree = GetDegree(nums);
        int smallest = nums.size() + 10;
        int i = 0, j = 0;
        unordered_map<int, int> elem_freqs;
        map<int, set<int>> degrees;

        for (auto e : nums) {
            elem_freqs[e] = 0;
            degrees[0].insert(e);
        }

        int greater_curr_degree = 0;
        while (i <= j && j < nums.size()) {
            if (i == j && i != 0) {
                j++;
                continue;
            }
            while (j < nums.size() && greater_curr_degree < degree) {
                int curr_degree = elem_freqs[nums[j]];
                Move(degrees, curr_degree, curr_degree + 1, nums[j]);
                Increment(elem_freqs, nums[j], 1);
                greater_curr_degree = degrees.rbegin()->first;
                if (greater_curr_degree < degree) j++;
            }
            while (i <= j && greater_curr_degree == degree) {
                smallest = min(smallest, j - i + 1);
                int curr_degree_left = elem_freqs[nums[i]];
                Move(degrees, curr_degree_left, curr_degree_left - 1, nums[i]);
                Increment(elem_freqs, nums[i], -1);
                greater_curr_degree = degrees.rbegin()->first;
                i++;
            }
            j++;
        }
        return smallest;
    }
};

struct Test {
    vector<int> input;
    int expected;
};

int main(void) {
    vector<Test> tests = {
        {
            {1, 2, 2, 3, 1},
            2
        },
        {
            {1,2,1,3,2},
            3
        },
        {
            {1},
            1
        },
        {
            {1,1},
            2
        }
    };

    bool succeed = true;

    int test_case = 0;
    for (auto test : tests) {
        Solution sol;
        int out = sol.findShortestSubArray(test.input);
        if (out != test.expected) {
            succeed = false;
            cout << "Failed on test #" << test_case << endl;
            cout << "Got " << out << ", expected " << test.expected << endl;
        }
        test_case++;
    }

    if (succeed) cout << "Good Job" << endl;
    else cout << "Keep trying" << endl;

    return 0;
}