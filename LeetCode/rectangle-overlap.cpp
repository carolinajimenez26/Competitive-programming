#include <iostream>
#include <vector>

using namespace std;

bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
   return min(rec1[2], rec2[2]) <= max(rec1[2], rec2[2]) &&
          min(rec1[2], rec2[2]) > max(rec1[0], rec2[0]) &&
          min(rec1[3], rec2[3]) <= max(rec1[3], rec2[3]) &&
          min(rec1[3], rec2[3]) > max(rec1[1], rec2[1]);
}

int main(void) {
    return 0;
}
