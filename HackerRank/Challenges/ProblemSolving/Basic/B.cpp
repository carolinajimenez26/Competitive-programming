#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<string> mostActive(vector<string> customers) {
  unordered_map<string, double> freqs;
  for (auto customer : customers) {
    freqs[customer]++;
  }
  vector<string> result;
  for (auto [customer, amount] : freqs) {
    double x = amount / customers.size();
    if (x >= 0.05) {
      result.push_back(customer);
    }
  }
  sort(result.begin(), result.end());
  return result;
}

void Print(const vector<string>& numbers) {
  for (auto s : numbers) cout << s << " ";
  cout << endl;
}

int main(void) {
  vector<string> customers = {
    "Omega",
    "Alpha",
    "Omega",
    "Alpha",
    "Omega",
    "Alpha",
    "Omega",
    "Alpha",
    "Omega",
    "Alpha",
    "Omega",
    "Alpha",
    "Omega",
    "Alpha",
    "Omega",
    "Alpha",
    "Omega",
    "Alpha",
    "Omega",
    "Beta",
  };
  vector<string> out = mostActive(customers);
  Print(out);
  return 0;
}