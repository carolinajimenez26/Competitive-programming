/*
Given a non-empty array of integers, return the third maximum number 
in this array. If it does not exist, return the maximum number. The 
time complexity must be in O(n).

Example 1:

Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.

Example 2:

Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is 
returned instead.

Example 3:

Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum 
distinct number.
Both numbers with value 2 are both considered as second maximum.

Problem source: https://leetcode.com/problems/third-maximum-number/
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int thirdMax(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    if (nums.size() < 3) return nums[nums.size() - 1];
    int diff = 1;
    int curr = nums[nums.size() - 1];
    int i;
    for (i = nums.size() - 1; i >= 0; i--) {
        if (nums[i] != curr) {
            diff++;
            curr = nums[i];
        }
        if (diff == 3) break;
    }
    if (diff < 3) { // max 3rd doesnt exists
        return nums[nums.size() - 1];
    }
    return i < 0 ? nums[0] : nums[i];
}

int main(void) {
    vector<vector<int> > input = {
        {3, 2, 1},
        {1, 2},
        {2, 2, 3, 1},
        {2,2,2,2,2,2},
        {2,2,2,1},
        {1},
        {2,2,2,1,1,1},
        {2,2,2,1,1,1,3,3,3},
        {1,2,3,4,5,6}
    };

    vector<int> expected = {
        1,
        2,
        1,
        2,
        2,
        1,
        2,
        1,
        4
    };

    bool succeed = true;

    for (int i = 0; i < input.size(); i++) {
        int sol = thirdMax(input[i]);
        if (sol == expected[i]) {
            cout << "Succeed" << endl;
        } else {
            cout << "Failure" << endl;
            cout << "Expected " << expected[i] << endl;
            cout << "Received " << sol << endl;
            succeed = false;
        }
    }

    if (succeed) {
        cout << "Good job" << endl;
    }

    return 0;
}