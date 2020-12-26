#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> students_queue = CreateQueue(students);
    int sandwiches_idx = 0;
    while (sandwiches_idx < sandwiches.size()) {
      int times = 0;
      while (!students_queue.empty() && times < students_queue.size() 
             && sandwiches[sandwiches_idx] != students_queue.front()) {
        int student = students_queue.front();
        students_queue.pop();
        students_queue.push(student);
        times++;
      }
      if (times >= students_queue.size()) break;
      students_queue.pop();
      sandwiches_idx++;
    }
    return sandwiches.size() - sandwiches_idx;
  }
private:
  queue<int> CreateQueue(const vector<int>& v) {
    queue<int> ans;
    for (auto e : v) ans.push(e);
    return ans;
  }
};

struct Test {
  vector<int> students, sandwiches;
  int expected;
};

int main(void) {
  vector<Test> tests = {
    { {1,1,0,0}, {0,1,0,1}, 0 },
    { {1,1,1,0,0,1}, {1,0,0,0,1,1}, 3 },
    { {1,1,1}, {0,0,0}, 3 },
    { {1,1,1}, {1,1,1}, 0 },
    { {1}, {0}, 1 },
    { {}, {}, 0 },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    Solution sol;
    int out = sol.countStudents(test.students, test.sandwiches);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}