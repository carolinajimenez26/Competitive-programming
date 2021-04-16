#include <iostream>
#include <vector>
using namespace std;

class PrefixSum {
public:
  PrefixSum(const vector<int>& v) {
    if (v.size() == 0) {
      return;
    }
    numbers.assign(v.size(), 0);
    numbers[0] = v[0];
    for (int i = 1; i < v.size(); i++) {
      numbers[i] = numbers[i - 1] + v[i];
    }
  }

  long Get(int from, int to) {
    if (from == 0) {
      return numbers[to];
    }
    return numbers[to] - numbers[from - 1];
  }

  void Print() {
    for (auto n : numbers) cout << n << " ";
    cout << endl;
  }
protected:
  vector<long> numbers;
};

struct PrefixSumZeros : public PrefixSum {
public:
  PrefixSumZeros(const vector<int>& v) : PrefixSum(v) {
    if (v.size() == 0) {
      return;
    }
    numbers.assign(v.size(), 0);
    if (v[0] == 0) {
      numbers[0] = 1;
    }
    for (int i = 1; i < v.size(); i++) {
      numbers[i] = numbers[i - 1];
      if (v[i] == 0) {
        numbers[i]++;
      }
    }
  }
};

vector<long> findSum(vector<int> numbers, vector<vector<int>> queries) {
  vector<long> result(queries.size(), 0);
  PrefixSum ps(numbers);
  PrefixSumZeros zeros(numbers);
  // ps.Print();
  // zeros.Print();
  for (int query = 0; query < queries.size(); query++) {
    int from = queries[query][0] - 1; // 1 index
    int to = queries[query][1] - 1;
    int x = queries[query][2];
    long first = ps.Get(from, to);
    long amount_zeros = zeros.Get(from, to);
    long second = x * amount_zeros;
    long partial = first + second;
    result[query] = partial;
  }
  return result;
}

void Print(const vector<long>& numbers) {
  for (auto n : numbers) cout << n << " ";
  cout << endl;
}

struct Test {
  vector<int> numbers;
  vector<vector<int>> queries;
  vector<long> expected;
};

int main(void) {
  const int MAX = 1e9;
  const int MAX_2 = 2e9;
  const long MAX_3 = 3e9;
  vector<Test> tests = {
    {
      {5,0,20,0},
      {
        {2, 4, 5},
        {1, 1, 10},
        {1, 4, -1},
      },
      {30, 5, 23},
    },
    {
      {-5, 0},
      {
        {2, 2, 20},
        {1, 2, 10},
      },
      {20, 5}
    },
    {
      {MAX,MAX,0},
      {
        {1, 2, 5},
        {1, 3, MAX}
      },
      {MAX_2, MAX_3},
    },
    {
      {1},
      {
        {1,1,10},
        {1,1,0}
      },
      {1,1}
    },
    {
      {0},
      {
        {1,1,10},
        {1,1,20},
        {1,1,-10}
      },
      {10, 20, -10}
    },
    {
      {0,0},
      {
        {1,1,10},
        {1,2,20},
        {1,2,-10}
      },
      {10, 40, -20}
    },
    {
      {MAX,-MAX},
      {
        {1,1,10},
        {1,2,20},
      },
      {MAX, 0}
    },
    {
      {MAX,MAX,MAX},
      {
        {1, 1, 20},
        {1, 2, 1000000000},
        {1, 3, -1000000000},
      },
      {MAX, MAX_2, MAX_3},
    },
    {
      {
        0,
        0,
        0,
        -1000000000,
        -1000000000,
        -1000000000,
      },
      {
        {1, 1, 20},
        {1, 2, 1000000000},
        {1, 3, -1000000000},
        {1, 6, 1000000000},
      },
      {
        20,
        2000000000,
        -3000000000,
        0,
      }
    }
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    vector<long> out = findSum(test.numbers, test.queries);
    if (out != test.expected) {
      cout << "Failed on test #" << tc << endl;
      Print(out);
      Print(test.expected);
      succeed = false;
    }
    tc++;
  }
  cout << (succeed ? "Good job" : "Keep trying") << endl;

  return 0;
}