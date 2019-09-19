#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
  int result = 0;
  int counter = 0;
  bool wentOut = true;
  for (auto c : s) {
    if (c == 'U') {
      counter++;
    } else {
      counter--;
    }
    if (counter < 0 && wentOut) {
      result++;
      wentOut = false;
    }
    if (counter >= 0) {
      wentOut = true;
    }
  }
  cout << result << endl;
  return result;
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string s;
  getline(cin, s);

  int result = countingValleys(n, s);

  fout << result << "\n";

  fout.close();

  return 0;
}
