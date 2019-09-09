#include<vector>
#include<iostream>
#include<cmath>
#include<numeric>
#include<algorithm>

using namespace std;

vector<int> SortByDigit(const vector<int>& data, const int base) {
  vector<int> freq(10);
  for (auto it : data) {
     freq[(it / base) % 10]++; 
  }
  vector<int> pos_by_digit(10);
  partial_sum(freq.begin(), freq.end(), pos_by_digit.begin());

  vector<int> ans(data.size());
  for (int i = data.size() - 1; i >= 0; i--) {
    int dig = (data[i] / base) % 10;
    int pos = pos_by_digit[dig];
    pos_by_digit[dig]--;
    ans[pos - 1] = data[i];
  }
  return ans;
}

vector<int> Radix(const vector<int>& data) {
  int max_ele = *max_element(data.begin(), data.end());
  int max_exp = ceil(log(max_ele)); 
  vector<int> next = data;
  for (int i = 0, base = 1; i <= max_exp; i++, base *= 10) {
    next = SortByDigit(next, base);
  }
  return next;
}

int main() {
  vector<int> input{2, 24, 45, 66, 75, 90, 170, 802};
  const auto output = Radix(input);
  for (const auto& it : output) {
    cout << it <<  " ";
  }
  cout << endl;
  return 0;
}

