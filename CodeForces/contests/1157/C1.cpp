#include<iostream>
#include<vector>
#include<deque>
#include<set>
#define dbg(x) cout << #x << ": " << (x) << endl
using namespace std;

void print(const vector<int>& v) {
    for (auto e : v) cout << e << " ";
    cout << endl;
}

void print(set<vector<int>>& moves) {
    for (auto v : moves) {
        print(v);
    }
    cout << endl;
}


int main(void) {
    int n;
    cin >> n;
    deque<int> nums(n);
    for (auto &it : nums) cin >> it;

    int last = 0;
    string ans;
    while (nums.size()) {
        if (nums[0] < nums.back()) {
            if (nums[0] > last) {
                last = nums[0];
                ans.push_back('L');
                nums.pop_front();
            } else if (nums.back() > last) {
                last = nums.back();
                ans.push_back('R');
                nums.pop_back();
            } else {
                break;
            }
        } else {
            if (nums.back() > last) {
                last = nums.back();
                ans.push_back('R');
                nums.pop_back();
            } else if (nums[0] > last) {
                last = nums[0];
                ans.push_back('L');
                nums.pop_front();
            } else {
                break;
            }
        }
    }
    cout << ans.size() << endl;
    cout << ans << endl;
    return 0;
}