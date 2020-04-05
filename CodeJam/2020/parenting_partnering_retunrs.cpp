#include <iostream>
#include <vector>
#define dbg(x) cout << #x << ": " << x << endl

using namespace std;

struct classcomp {
  bool operator() (const pair<int,int>& left, const pair<int,int>& right) const
  {
    if (left.first == right.first) {
      return left.second < right.second;
    }
    return left.first < right.first;
  } // order by starting time
} cmp;

bool Overlaps(pair<int,int> op1, pair<int,int> op2) {
  return max(op1.first, op2.first) < min(op1.second, op2.second);
}

bool Overlaps(pair<int,int> op, vector<pair<int,int>>& a) {
  for (auto p : a) {
    if (Overlaps(op, p)) {
      return true;
    }
  }
  a.push_back(op);
  return false;
}

int Find(const vector<pair<int,int>>& a, pair<int, int> e) {
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == e) return i;
  }
  return -1;
}

string GenerateSchedule(vector<pair<int,int>>& a, vector<pair<int,int>>&b,
  char c_a, char c_b, const vector<pair<int,int>>& in) {
  string result = "";
  vector<pair<int,int>>::iterator it;
  vector<bool> visited_a(a.size(), false);

  for (auto e : in) {
    // dbg(e.first);dbg(e.second);
    int idx = Find(a, e);
    if (idx != -1 && visited_a[idx] == false) {
      // dbg(c_a);
      result.push_back(c_a);
      visited_a[idx] = true;
    } else {
      result.push_back(c_b);
      // dbg(c_b);
    }
  }
  return result;
}

void print(const vector<pair<int,int>>& vp) {
  for (auto p : vp) {
    cout << "(" << p.first << "," << p.second << "), ";
  }
  cout << endl;
}

int main(void) {
  int tc, N;
  cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cin >> N;
    vector<pair<int,int>> in(N), in_copy(N), a, b;
    for (int j = 0; j < N; j++) {
      int s, e;
      cin >> s >> e;
      in[j] = {s,e};
      in_copy[j] = {s,e};
    }
    sort(in.begin(), in.end(), cmp);
    // print(in);
    bool imposible = false;

    for (auto op : in) {
      if (Overlaps(op, a) && Overlaps(op, b)) {
        imposible = true;
      }
    }
    // print(a);
    // print(b);
    if (imposible) {
      cout << "Case #" << i << ": " << "IMPOSSIBLE" << endl;
    } else {
      cout << "Case #" << i << ": " << GenerateSchedule(a, b, 'C', 'J', in_copy) << endl;
    }
  }
  return 0;
}