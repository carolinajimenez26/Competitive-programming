#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<pair<int,int>> GetValidBrackets(const string& s) {
  vector<pair<int,int>> ans;
  stack<int> openings;
  int i = 0;
  for (auto bracket : s) {
    if (bracket == '(') openings.push(i);
    else {
      if (!openings.empty()) {
        ans.push_back({openings.top(), i});
        openings.pop();
      }
    }
    i++;
  }
  return ans;
}

bool Intersects(pair<int,int> a, pair<int,int> b) {
  return max(a.first, b.first) <= min(a.second, b.second);
}

vector<pair<int,int>> RemoveInnerBrackets(const vector<pair<int,int>>& v) {
  vector<pair<int,int>> ans;
  if (v.size() == 0) return ans;
  ans.push_back(v.back());
  int curr = v.size() - 1;
  for (int i = v.size() - 2; i >= 0; i--) {
    if (!Intersects(v[curr], v[i])) {
      curr = i;
      ans.push_back(v[i]);
    }
  }
  return ans;
}

inline bool AreContinuos(pair<int,int> a, pair<int,int> b) {
  return a.first - 1 == b.second;
}

vector<pair<int,int>> JoinContinuos(const vector<pair<int,int>>& v) {
  if (v.size() == 0 || v.size() == 1) return v;
  vector<pair<int,int>> ans;
  ans.push_back(v[0]);
  for (int i = 1; i < v.size(); i++) {
    if (AreContinuos(ans.back(), v[i])) {
      pair<int, int> tmp = ans.back();
      ans.pop_back();
      ans.push_back({ v[i].first, tmp.second });
    } else {
      ans.push_back(v[i]) ;
    }
  }
  return ans;
}

void Print(const vector<pair<int,int>>& v) {
  for (auto e : v) {
    cout << e.first << ", " << e.second << endl;
  }
  cout << endl;
}

int main(void) {
  string s;
  cin >> s;
  vector<pair<int,int>> valid_brackets = GetValidBrackets(s);
  // Print(valid_brackets);
  if (valid_brackets.empty()) {
    cout << "0 1" << endl;
    return 0;
  }

  valid_brackets = RemoveInnerBrackets(valid_brackets);
  // Print(valid_brackets);
  valid_brackets = JoinContinuos(valid_brackets);
  // Print(valid_brackets);
  int longest = 0;
  for (auto p : valid_brackets) {
    int interval_size = p.second - p.first + 1;
    longest = max(longest, interval_size);
  }
  int equal_longest = 0;
  for (auto p : valid_brackets) {
    if (p.second - p.first + 1 == longest) {
      equal_longest++;
    }
  }
  cout << longest << " " << equal_longest << endl;

  return 0;
}