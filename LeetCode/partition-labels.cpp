#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <limits>
#define dbg(x) cout << #x << ": " << x << endl
using namespace std;

void print(vector<int> v) {
  for (auto i : v) cout << i << " ";
  cout << endl;
}

void print(vector<pair<int, int>> v) {
  for (auto i : v) cout << i.first << " ";
  cout << endl;
  for (auto i : v) cout << i.second << " ";
  cout << endl;
}

vector<int> partitionLabels(string S) {
  vector<int> result;
  vector<pair<int, int>> info(26, {S.size(), -1});
  for (int i = 0; i < S.size(); i++) {
    int idx = S[i] - 'a';
    if (info[idx].first > i) {
      info[idx].first = i;
    }
    if (info[idx].second < i) {
      info[idx].second = i;
    }
  }
  sort(info.begin(), info.end());
  //print(info);

  for (int i = 0; i < info.size() && info[i].first < S.size();) {
    int target = info[i].second;
    int started = i;
    while (i < info.size() && info[i].first <= target) {
      target = max(target, info[i].second);
      i++;
    }
    // dbg(started);dbg(i);
    result.push_back(target - info[started].first + 1);
  }
  return result;
}

int main(int argc, char **argv) {
  set<int> valid;
  for (int i = 1; i < argc; i++) {
    valid.insert(atoi(argv[i]));
  }

  vector<string> input = {
    "ababcbacadefegdehijhklij",
    "aaaaabbbc",
    "ababcbacadefegdehijhklijdjsssidkfjidsfjsioajfdiasdfi",
  };
  vector<vector<int>> expectedOutput = {
    {9,7,8},
    {5,3,1},
    {52},
  };
  bool succeed = true;
  // for (int i = 0; i < input.size(); i++) {
  //   if (valid.count(i) == 0) continue;
  //   vector<int> output = partitionLabels(input[i]);
  //   if (output != expectedOutput[i]) {
  //     succeed = false;
  //     cout << "Expected "; print(expectedOutput[i]);
  //     cout << "Received "; print(output);
  //   }
  // }
  for (auto it : valid) {
      if (it >= input.size()) continue;
      vector<int> output = partitionLabels(input[it]);
      if (output != expectedOutput[it]) {
        succeed = false;
        cout << "Expected "; print(expectedOutput[it]);
        cout << "Received "; print(output);
      }
  }

  if (succeed) cout << "Good Job" << endl;
  else cout << "Keep trying" << endl;

  return 0;
}
