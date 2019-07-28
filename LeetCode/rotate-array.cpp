/*
Given an array, rotate the array to the right by k steps, where k is 
non-negative.
Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]

Problem source: https://leetcode.com/problems/rotate-array/
*/

#include <iostream>
#include <vector>
// #define dbg(x) cout << #x << ": " << x << endl

using namespace std;

void rotate(vector<int>& nums, int k) {
    int tmp, tmp2;

    for(int j = 0; j < k % nums.size(); j++) {
        tmp = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            tmp2 = nums[i];
            nums[i] = tmp;
            tmp = tmp2;
        }
        nums[0] = tmp;
    }
}

int main(void) {
    vector<vector<int> > input = {
        {1,2,3,4,5,6,7},
        {-1,-100,3,99},
        {1,2,3},
        {1,2,3},
        {1,2,3},
        {1,2,3}
    };

    vector<int> k = {3, 2, 0, 3, 4, 6};

    vector<vector<int> > expected = {
        {5,6,7,1,2,3,4},
        {3,99,-1,-100},
        {1,2,3},
        {1,2,3},
        {3,1,2},
        {1,2,3}
    };

    bool succeed = true;

    for (int i = 0; i < input.size(); i++) {
        rotate(input[i], k[i]);
        if (input[i] == expected[i]) {
            cout << "Succeed" << endl;
        } else {
            cout << "Failure" << endl;
            // cout << "Expected " << expected[i] << endl;
            // cout << "Received " << input[i] << endl;
            succeed = false;
        }
    }

    if (succeed) {
        cout << "Good job" << endl;
    }

    return 0;
}