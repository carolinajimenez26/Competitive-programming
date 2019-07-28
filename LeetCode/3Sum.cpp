/*
Given an array nums of n integers, are there elements a, b, c in nums 
such that a + b + c = 0? Find all unique triplets in the array which 
gives the sum of zero.

Problem source: https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/776/
*/
#include <iostream>
#include<vector>
#include<set>
#include <algorithm>
#define dbg(x) cout << #x << ": " << x << endl

using namespace std;


void print(vector<vector<int>> vvi) {
    for (auto vi : vvi) {
        for (auto i : vi) {
            cout << i << " ";
        }
        cout << endl;
    } 
    cout << endl;
}

void twoSum(vector<int>& nums, int target, int idx,
            set<vector<int> > &sol) {
    
    int i = idx + 1, j = nums.size() - 1;
    while (i < j) { // O(nums.size() * log sol.size())
        int a = target - nums[i];
        int b = target - nums[j];
        if (a < nums[j]) {
            j--;
        }
        if (b > nums[i]) {
            i++;
        }
        if (a == nums[j] && b == nums[i]) {
            vector<int> v = {nums[idx], nums[i], nums[j]};
            sort(v.begin(), v.end());
            if (!sol.count(v)) { // O(log sol.size())
                sol.insert(v);
            }
            i++;
        }
    }
}

vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int> > setSol;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) { // O(nums.size())
        // a + b + c = 0
        // b + c = -a
        twoSum(nums, (-1 * nums[i]), i, setSol);
    }
    vector<vector<int> > sol(setSol.size());
    copy(setSol.begin(), setSol.end(), sol.begin());
    sort(sol.begin(), sol.end());
    return sol;
}

int main (void) {
    vector<vector<int> > input = {
        {0, 0, 0},
        {-1,0,1,2,-1,-4},
        {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0},
        {0,3,2,4,-3,-1,-4,-3,-3,2},
        {5,-7,3,-3,5,-10,4,8,-3,-8,-3,-3,-1,-8,6,4,-4,7,2,-5,-2,-7,-3,7,2,4,-6,5}
    };
    vector<vector<vector<int> > > expected = {
        {{0, 0, 0}},
        {{-1,-1,2}, {-1,0,1}},
        {{-5,1,4},{-4,0,4},{-4,1,3},{-2,-2,4},{-2,1,1},{0,0,0}},
        {{-4,0,4},{-4,2,2},{-3,-1,4},{-3,0,3}},
        {{-10,2,8},{-10,3,7},{-10,4,6},{-10,5,5},{-8,2,6},{-8,3,5},{-8,4,4},{-7,-1,8},{-7,2,5},{-7,3,4},{-6,-2,8},{-6,-1,7},{-6,2,4},{-5,-3,8},{-5,-2,7},{-5,-1,6},{-5,2,3},{-4,-3,7},{-4,-2,6},{-4,-1,5},{-4,2,2},{-3,-3,6},{-3,-2,5},{-3,-1,4},{-2,-1,3}}
    };

    bool succeed = true;

    for (int i = 0; i < input.size(); i++) {
        vector<vector<int> > sol = threeSum(input[i]);
        if (sol != expected[i]) {
            cout << "Failure" << endl;
            succeed = false;
            cout << "Expected: " << endl;
            print(expected[i]);
            dbg(expected[i].size());
            cout << "Received: " << endl;
            print(sol);
            dbg(sol.size());
            break;
        } else {
            cout << "Succeed" << endl;
        }
    }

    if (succeed) {
        cout << "Good job" << endl;
    }

    return 0;
}