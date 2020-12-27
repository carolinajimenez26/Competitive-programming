#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits>
using namespace std;

class Solution {
public:
  int minJumps(vector<int>& arr) {
    if (arr.empty() || arr.size() == 1) return 0;
    for (int i = 0; i < arr.size(); i++) {
      num_positions[arr[i]].push_back(i);
    }
    nums = arr;
    distance.assign(arr.size(), INF);
    return MinJumps(arr.size() - 1);
  }
private:
  unordered_map<int, vector<int>> num_positions;
  vector<int> distance;
  vector<int> nums;
  const int INF = numeric_limits<int>::max();

  bool IsValid(int idx) {
    return idx >= 0 && idx < nums.size();
  }

  int MinJumps(int idx) {
    queue<int> q;
    q.push(idx);
    distance[idx] = 0;
    while (!q.empty()) {
      int front = q.front();
      q.pop();
      vector<int> neighs = num_positions[nums[front]];
      num_positions[nums[front]].clear();
      neighs.push_back(front + 1);
      neighs.push_back(front - 1);
      for (auto neigh : neighs) {
        if (IsValid(neigh) && distance[neigh] == INF) {
          distance[neigh] = distance[front] + 1;
          q.push(neigh);
        }
      }
    }
    return distance[0];
  }
};

struct Test {
  vector<int> arr;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    { {1,2}, 1 },
    { {1,2,1}, 1 },
    { {1,2,3,2}, 2 },
    { {2,1,3,2}, 1 },
    { {100,-23,-23,404,100,23,23,23,3,404}, 3 },
    { {7,6,9,6,9,6,9,7}, 1 },
    { {7}, 0 },
    { {6,1,9}, 2 },
    { {11,22,7,7,7,7,7,7,7,22,13}, 3 },
    { {3,1,10,3,2,10}, 3 },
    { {1,2,3,2,1,2,3,2}, 2 },
    { {1,1,10,1,3,4,10}, 3 },
    { {10,3,2,1,10,1,1}, 3 },
    { {51,64,-15,58,98,31,48,72,78,-63,92,-5,64,-64,51,-48,64,48,-76,-86,-5,-64,-86,-47,92,-41,58,72,31,78,-15,-76,72,-5,-97,98,78,-97,-41,-47,-86,-97,78,-97,58,-41,72,-41,72,-25,-76,51,-86,-65,78,-63,72,-15,48,-15,-63,-65,31,-41,95,51,-47,51,-41,-76,58,-81,-41,88,58,-81,88,88,-47,-48,72,-25,-86,-41,-86,-64,-15,-63},
       4 },
    { {51,64,-15,46,56,-15,-63}, 4 },
    { {1,1,1,1,1,1,2}, 2 },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.minJumps(test.arr);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}
