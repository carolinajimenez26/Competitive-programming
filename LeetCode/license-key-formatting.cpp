#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string licenseKeyFormatting(string S, int K) {
  string helper = "";
  vector<string> groups;
  for (int i = S.size() - 1; i >= 0; i--) {
    if (S[i] != '-') {
      helper.push_back(S[i]);
    }
    if (helper.size() == K) {
      groups.push_back(helper);
      helper = "";
    }
  }
  if (helper.size() != 0) {
    groups.push_back(helper);
  }

  for (int i = 0; i < groups.size(); i++) {
    reverse(groups[i].begin(),groups[i].end());
  }

  string result = "";
  for (int i = groups.size() - 1; i >= 0; i--) {
    result += groups[i];
    result.push_back('-');
  }

  if (result.back() == '-') result.pop_back();

  string upper = "";
  transform(result.begin(), result.end(), back_inserter(upper), ::toupper);
  return upper;
}

int main(void) {
  return 0;
}
