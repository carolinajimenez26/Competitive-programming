#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> frec;
    multimap<int, int> frec_inv;
    vector<int> result;
    for (auto num : nums) {
        if (frec.count(num)) frec[num] += 1;
        else frec[num] = 1;
    }
    for (auto e : frec) {
        frec_inv.insert({e.second, e.first});
    }
    int i = 0;
    for (auto rit = frec_inv.rbegin(); rit != frec_inv.rend(); ++rit) {
        if (i == k) break;
        result.push_back(rit->second);
        i++;
    }
    return result;
}

int main(void) {
    return 0;
}
