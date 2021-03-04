#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

double GetMean(const vector<int>& v) {
  double result = 0;
  for (auto e : v) {
    result += e;
  }
  result /= v.size();
  return result;
}

double GetMedian(const vector<int>& v) {
  int middle = v.size() / 2;
  if (v.size() % 2 != 0) {
    return v[middle];
  }
  double result = (v[middle] + v[middle - 1]) / 2.0;
  return result;
}

int GetAmount(const vector<int>& v, int target, int& idx) {
  int result = 0;
  while (idx < v.size() && v[idx] == target) {
    result++;
    idx++;
  }
  return result;
}

int GetMode(const vector<int>& v) {
  int idx = 0;
  int biggest_freq = 0;
  int result = numeric_limits<int>::max();
  while (idx < v.size()) {
    int next_idx = idx;
    int amount = GetAmount(v, v[idx], next_idx);
    if (amount >= biggest_freq) {
      if (amount > biggest_freq) {
        biggest_freq = amount;
        result = v[idx];
      } else {
        result = min(result, v[idx]);
      }
    }
    idx = next_idx;
  }
  return result;
}

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
  int size;
  cin >> size;
  vector<int> nums(size);
  for (int i = 0; i < size; i++) {
    cin >> nums[i];
  }
  sort(nums.begin(), nums.end());
  cout << GetMean(nums) << endl;
  cout << GetMedian(nums) << endl;
  cout << GetMode(nums) << endl;
  return 0;
}
