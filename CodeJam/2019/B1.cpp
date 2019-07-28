#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

#define dbg(x) cout << #x << ": " << x << endl

void print(vector<pair<int,int>>& v) {
  for (auto p : v) {
    cout << p.first << ", " << p.second <<  endl;
  }
  cout << endl;
}

vector<pair<int,int>> createSteps(string& path) {
  vector<pair<int,int>> steps;
  steps.push_back(make_pair(0,0));
  pair<int,int> last_move;
  for (int i = 0; i < path.size(); i++) {
    last_move = steps.back();
    if (path[i] == 'E') {
      steps.push_back({last_move.first, last_move.second + 1});
    } else {
      steps.push_back({last_move.first + 1, last_move.second});
    }
  }
  return steps;
}

string createSteps(vector<pair<int,int>>& steps) {
  string result = "";
  pair<int, int> prev = steps[0];
  for (int i = 1; i < steps.size(); i++) {
    if (steps[i].first == prev.first) {
      result.push_back('E');
    } else {
      result.push_back('S');
    }
    prev = steps[i];
  }
  return result;
}

bool isValid(const pair<int,int>& cell, int N) {
  return cell.first >= 0 && cell.first < N && cell.second >= 0 && cell.second < N;
}

pair<int, int> getDifferentMove(const vector<pair<int,int>>& steps, int i) {
  pair<int,int> prev_move = steps[i - 1];
  pair<int,int> next_move = steps[i];

  if (prev_move.first == next_move.first) { // moved to E
    return {prev_move.first + 1, prev_move.second};
  } else { // moved to S
    return {prev_move.first, prev_move.second + 1};
  }
}

bool check(const vector<pair<int,int>>& steps1,
           const vector<pair<int,int>>& steps2) {

   for (int i = 0; i < steps1.size() - 1; i++) {
     if (steps1[i] == steps2[i] && steps1[i + 1] == steps2[i + 1]) {
       return false;
     }
   }
   return true;
}

bool tryMove(int i, const vector<pair<int,int>>& Lydia_steps,
             vector<pair<int,int>>& my_steps, int N) {

  // dbg("----------");
  // dbg(i);
  // print(my_steps);
  pair<int,int> last_move = my_steps.back(), new_move;
  if (!isValid(last_move, N)) return false;
  if (my_steps.size() == Lydia_steps.size()) {
    return last_move.first == N - 1 && last_move.second == N - 1 &&
           check(my_steps, Lydia_steps);
  }

  if (Lydia_steps[i - 1] == my_steps[i - 1]) {
    new_move = getDifferentMove(Lydia_steps, i);
    // dbg(new_move.first); dbg(new_move.second);
    my_steps.push_back(new_move);
  } else {
    my_steps.push_back({last_move.first, last_move.second + 1});
  }

  bool succed = tryMove(i + 1, Lydia_steps, my_steps, N);
  // dbg(succed);
  if (succed) return true;

  new_move = getDifferentMove(my_steps, i);
  my_steps.pop_back();
  my_steps.push_back(new_move);

  succed = tryMove(i + 1, Lydia_steps, my_steps, N);
  // dbg(succed);
  if (succed) return true;

  my_steps.pop_back();

  return succed;
}

string findOtherPath(int N, string& Lydia_path) {
  vector<pair<int,int>> Lydia_steps = createSteps(Lydia_path);
  // print(Lydia_steps);
  vector<pair<int,int>> my_steps;
  my_steps.push_back(make_pair(0,0));

  tryMove(1, Lydia_steps, my_steps, N);
  // print(my_steps);
  return createSteps(my_steps);
}

int main(void) {
  int tc, c = 1, n;
  string path;
  cin >> tc;
  while (tc--) {
    cin >> n;
    cin >> path;
    cout << "Case #" << c << ": " << findOtherPath(n, path) << endl;
    c++;
  }
  return 0;
}
