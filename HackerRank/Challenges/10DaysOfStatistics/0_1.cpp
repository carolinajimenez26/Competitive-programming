#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iomanip>
using namespace std;

double GetWeightedMean(const vector<int>& v, const vector<int>& weights) {
  double partial_result = 0.0;
  double weights_sum = accumulate(weights.begin(), weights.end(), 0);
  for (int i = 0; i < v.size(); i++) {
    partial_result += (v[i] * weights[i]);
  }
  double result = partial_result / weights_sum;
  return result;
}

int main() {
  int size;
  cin >> size;
  vector<int> nums(size);
  vector<int> weights(size);
  for (int i = 0; i < size; i++) {
    cin >> nums[i];
  }
  for (int i = 0; i < size; i++) {
    cin >> weights[i];
  }
  double result = GetWeightedMean(nums, weights);
  cout << fixed << setprecision(1) << result << endl;
  return 0;
}
