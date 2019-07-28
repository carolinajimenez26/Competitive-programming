#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

vector<int> prefixMultLeft(vector<int> v) {
  vector<int> result(v.size());
  result[0] = v[0];
  for (int i = 1; i < v.size(); i++) {
    result[i] = result[i - 1] * v[i];
  }
  return result;
}

vector<int> prefixMultRight(vector<int> v) {
  vector<int> result(v.size());
  int size = result.size() - 1;
  result[size] = v.back();
  for (int i = size - 1; i >= 0; i--) {
    result[i] = result[i + 1] * v[i];
  }
  return result;
}

vector<int> productExceptSelf(vector<int>& nums) {
  vector<int> result(nums.size());
  vector<int> mult_left = prefixMultLeft(nums);
  // print(mult_left);
  vector<int> mult_right = prefixMultRight(nums);
  // print(mult_right);
  for (int i = 0; i < result.size(); i++) {
    result[i] = (i - 1 >= 0 ? mult_left[i - 1] : 1);
    result[i] *= (i + 1 < mult_right.size() ? mult_right[i + 1] : 1);
  }
  return result;
}

int main(void) {
  vector<int> input = {1, 2, 3, 4};
  vector<int> output = productExceptSelf(input);
  print(output);
  return 0;
}
