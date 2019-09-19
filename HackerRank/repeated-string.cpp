#include <bits/stdc++.h>

using namespace std;

long Count(string& s, char c) {
  long result = 0;
  for (auto e : s) {
    if (e == c) result++;
  }
  return result;
}

string CreateStringWith(long expected_size, string& s) {
  string result = "";
  if (expected_size == 0 || s.size() == 0) return result;
  int s_pointer = 0;
  while (result.size() < expected_size) {
    result.push_back(s[s_pointer % s.size()]);
    s_pointer++;
  }
  return result;
}

// Complete the repeatedString function below.
long repeatedString(string s, long n) {
  long long result = 0;
  long q = n / s.size();
  long r = n % s.size();
  long a_count = Count(s, 'a');
  string rest_string = CreateStringWith(r, s);
  result = (a_count * q) + Count(rest_string, 'a');
  return result;
}

int main()
{
  ofstream fout(getenv("OUTPUT_PATH"));

  string s;
  getline(cin, s);

  long n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  long result = repeatedString(s, n);

  fout << result << "\n";

  fout.close();

  return 0;
}
