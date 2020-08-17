#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> distributeCandies(int candies, int num_people) {
    vector<int> people(num_people, 0);
    int i = 0;
    while (candies > 0) {
      if (i + 1 <= candies) {
        people[i % num_people] += (i + 1);
        candies -= (i + 1);
      } else {
        people[i % num_people] += candies;
        candies = 0;
      }
      i++;
    }
    return people;
  }
};

int main(void) {
  return 0;
}