#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
  double angleClock(int hour, int minutes) {
    hour %= 12;
    double hour_angle = (360 * double(hour * 60 + minutes)) / (12 * 60);
    double minutes_angle = (360 * minutes) / 60;
    double diff = abs(minutes_angle - hour_angle);
    return min(diff, 360 - diff);
  }
};

struct Test {
  int hour, minutes;
  double ans;
};

int main(void) {
  vector<Test> tests = {
    { 12,30,165 },
    { 3,30,75 },
    { 3,15,7.5 },
    { 4,50,155 },
    { 12,0,0 },
  };
  int tc = 0;
  bool succeed = true;
  Solution sol;
  for (auto test : tests) {
    double out = sol.angleClock(test.hour, test.minutes);
    if (out != test.ans) {
      cout << "Failed on test #" << tc << ". Found " << out << ", expected " << test.ans << endl;
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;
  return 0;
}