#include <iostream>
#include <vector>

using namespace std;

const int len[] = {1, 7, 30};
struct State {
  bool seen;
  int best;
  State() : seen(false), best(-1) {}
};
State state[366][4];

int getValue(int op, vector<int>& costs, vector<int>& days, int index_day, int& result) {
  int n = days[index_day];
  for (int i = 0; i < len[op] && index_day < days.size(); i++, n++) {
    if (n == days[index_day]) {
      index_day++;
    }
  }
  result = costs[op];
  return index_day;
}

int mincostTicketsHandler(const vector<int>& days, const vector<int>& costs, int index_day,
                          int op) {
  if (index_day >= days.size()) return 0;

  if (state[index_day][op].seen) {
    return state[index_day][op].best;
  }
  state[index_day][op].seen = true;

  int current_result;
  index_day = getValue(op, costs, days, index_day, current_result);

  int op1 = mincostTicketsHandler(days, costs, index_day, 0);
  int op2 = mincostTicketsHandler(days, costs, index_day, 1);
  int op3 = mincostTicketsHandler(days, costs, index_day, 2);

  int min_result = min(op1, min(op2, op3));
  return state[index_day][op].best = min_result + current_result;
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
  int op1 = mincostTicketsHandler(days, costs, 0, 0);
  int op2 = mincostTicketsHandler(days, costs, 0, 1);
  int op3 = mincostTicketsHandler(days, costs, 0, 2);

  return min(op1, min(op2,op3));
}

int main(void) {
  return 0;
}
