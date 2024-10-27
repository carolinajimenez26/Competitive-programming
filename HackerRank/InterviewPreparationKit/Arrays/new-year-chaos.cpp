#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl

// [2, 3, 1, 5, 4] --> [2,1,3,5,4] --> [2,1,3,4,5] --> [1,2,3,4,5] 
// [2, 1, 5, 3, 4] --> [1,2,5,3,4] --> [1,2,3,5,4] --> [1,2,3,4,5]
// [3, 1, 2, 5, 4] --> [1,3,2,5,4] --> [1,2,3,5,4] --> [1,2,3,4,5]

// [1,2,5,4,3] --> [1,2,4,5,3]
// [1,1,0,0,0] --> [1,1,0,0,0]

// [1,2,5,4,3] --> [1,2,4,5,3] --> [1,2,4,3,5] --> [1,2,3,4,5]

// [0 0 0 0 0 0 0 0] --> [0 0 0 0 0 0 0 0] -> [0 0 0 0 1 0 0 0] ->  [0 0 0 0 2 1 1 1] -> [0 0 0 0 2 1 1 1] -> [0 0 0 0 2 1 2 2]
// [1 2 5 3 7 8 6 4] --> [2 5 3 7 8 6 4] -->  [5 7 8 6 4]       --> [5 7 8 6]         -> [7,8,6]           -> [7,8]
//  1 2 3 4 5 6 7 8       1 2 3 4 5 6 7 8


// [1 2 5 3 7 8 6 4] -> 
//      2   2 2 1 0

void Print(const vector<int>& v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

void Print(const set<int>& v) {
  for (auto e : v) cout << e + 1 << " ";
  cout << endl;
}

int MoveUntilOrdered(vector<int>& q, int idx, set<int>& to_process) {
  int moves = 0;
  while (idx < q.size() - 1 && q[idx] > q[idx + 1]) {
    dbg("----"); dbg(q[idx]);
    Print(q); Print(to_process);
    swap(q[idx], q[idx + 1]);
    if (q[idx] == idx + 1) {
      to_process.erase(idx);
    }
    moves++;
    idx++;
  }
  return moves;
}

set<int> CreateSet(int size) {
  set<int> result;
  for (int i = 0; i < size; i++) {
    result.insert(i);
  }
  return result;
}

void minimumBribes(vector<int> q) {
  int result = 0;
  bool too_chaotic = false;
  set<int> to_process = CreateSet(q.size());
  while (to_process.size()) {
    int next = *to_process.begin();
    dbg(next);
    int moves = MoveUntilOrdered(q, next, to_process);
    dbg(moves);
    to_process.erase(next);
    if (moves > 2) {
      too_chaotic = true;
      break;
    }
    result += moves;
  }
  if (too_chaotic) {
    cout << "Too chaotic" << endl;
  } else {
    cout << result << endl;
  }
}

int main(void) {
  vector<vector<int>> tests = {
    // {2, 1, 5, 3, 4},
    // {2, 5, 1, 3, 4},
    {1, 2, 5, 3, 7, 8, 6, 4},
  };
  for (auto test : tests) {
    Print(test);
    minimumBribes(test);
  }

  return 0;
}