/*
Given an array with n integers, your task is to check if it could 
become non-decreasing by modifying at most 1 element.

We define an array is non-decreasing if array[i] <= array[i + 1] 
holds for every i (1 <= i < n). 
*/

#include<iostream>
#include<vector>

using namespace std;

int fixProblem(vector<int> nums, int idx_problem) {
    if (idx_problem - 1 < 0) 
        return idx_problem + 1;

    if (idx_problem + 1 >= nums.size()) 
        return idx_problem - 1;

    return max(nums[idx_problem - 1], nums[idx_problem + 1]);
}

bool checkPossibility(vector<int>& nums) {

    if (nums.size() == 0) return false;
    if (nums.size() == 1) return true;

    bool problem = false;

    if (nums[0] > nums[1]) {
        problem = true;
        nums[0] = nums[1];
    }

    for (int i = 1; i < nums.size() - 1; i++) {
        if (nums[i] < nums[i - 1] && nums[i] > nums[i + 1]) {
            if (problem) return false;
            problem = true;
            nums[i] = fixProblem(nums, i);
            continue;
        }
        if (nums[i] < nums[i - 1]) {
            if (problem) return false;
            problem = true;
            nums[i] = nums[i - 1];
            continue;
        }
        if (nums[i] > nums[i + 1]) {
            if (problem) return false;
            if (nums[i + 1] <= nums[i - 1]) {
                continue;
            } else {
                problem = true;
                nums[i] = fixProblem(nums, i);
            }
        }
    }

    if (nums[nums.size() - 1] < nums[nums.size() - 2]) {
        if (problem) return false;
    }

    return true;
}

int main(void) {
    vector<vector<int> > input = {
        {4,2,3},
        {4,2,1},
        {1,1,1,1},
        {1,2,1,2},
        {1,2,3,2},
        {1,4},
        {1},
        {4,2,3,1,1,1},
        {3,4,2,3},
        {2,3,3,2,4},
        {1,4,2,3,1,1,1},
        {-1,4,2,3}
    };
    vector<bool> expected = {
        true,
        false,
        true,
        true,
        true,
        true,
        true,
        false,
        false,
        true,
        false,
        true
    };

    bool succeed = true;

    for (int i = 0; i < input.size(); i++) {
        bool sol = checkPossibility(input[i]);
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