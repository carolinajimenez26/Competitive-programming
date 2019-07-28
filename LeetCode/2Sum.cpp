/*
Given an array of integers, return indices of the two numbers such that 
they add up to a specific target.
You may assume that each input would have exactly one solution, and you
may not use the same element twice.

Problem source: https://leetcode.com/problems/two-sum/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define dbg(x) cout << #x << ": " << x << endl

using namespace std;

void print(vector<int> v) {
    for (auto e : v) {
        cout << e << " ";
    }
    cout <<endl;
}

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, vector<int> > ori(nums.size()); // keeps the order of the original vector

    for (int i = 0; i < nums.size(); i++) {
        ori[nums[i]].push_back(i);
    }

    sort(nums.begin(), nums.end());

    int i = 0, j = nums.size() - 1;
    while (i <= j) {
        int a = target - nums[i];
        int b = target - nums[j];
        if (a < nums[j]) {
            j--;
        }
        if (b > nums[i]) {
            i++;
        }
        if (a == nums[j] && b == nums[i]) {
            // dbg(i); dbg(j);
            if (nums[i] == nums[j]) {
                int minIdx = min(ori[nums[i]][0], ori[nums[j]][1]);
                int maxIdx = max(ori[nums[i]][0], ori[nums[j]][1]);
                return {minIdx, maxIdx};  
            } else {
                int minIdx = min(ori[nums[i]][0], ori[nums[j]][0]);
                int maxIdx = max(ori[nums[i]][0], ori[nums[j]][0]);
                return {minIdx, maxIdx};    
            }
        }
    }
}

int main(void) {
    vector<vector<int> > inputs = {
        {2, 7, 11, 15},
        {3, 2, 4},
        {7, 3, 2, 1, 7, 8},
        {3,2,3},
        {10, 11, 25, 10, 10, 10, 1}
    };
    vector<int> targets = {9, 6, 4, 6, 12};
    vector<vector<int> > expected = {
        {0, 1}, 
        {1, 2}, 
        {1, 3},
        {0, 2},
        {1, 6}
    };
    bool succeed = true;

    for (int i = 0; i < inputs.size(); i++) {
        vector<int> sol = twoSum(inputs[i], targets[i]);
        if (sol == expected[i]) {
            cout << "Succeed" << endl;
        } else {
            cout << "Failure" << endl;
            succeed = false;
            cout << "Expected: " << endl;
            print(expected[i]);
            cout << "Received: " << endl;
            print(sol);
        }
        // return 0;
    }

    if (succeed) {
        cout << "Good job" << endl;
    }

    return 0;
}