#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;
#define dbg(x) cout << #x << ": " << x << endl
#define INF numeric_limits<int>::max()
using int64 = long long int;

bool IsValid(const vector<int>& v, int max_sum) {
  int acc = 0;
  for (int i = 0; i < v.size() - 1; i++) {
    if (abs(v[i] - v[i + 1]) > 1 || acc > max_sum) {
      return false;
    }
    acc += v[i];
  }
  acc += v.back();
  return acc <= max_sum;
}

int GetMaxElement(int max_sum, int k) {

  for (int i = max_sum; i >= 0; i--) {
    int before = v[k];
    v[k] = i;
    
    v[k] = before;
  }
}

int maxElement(int n, int max_sum, int k) {
  
}

struct Test {

};

int main(void) {
  vector<Test> tests = {
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    int out = 1; 
    if (out != test.expected) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.expected << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;

  return 0;
}