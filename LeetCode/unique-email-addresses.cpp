#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int numUniqueEmails(vector<string> emails) {
    set<string> result;
    string s;
    for (auto email : emails) {
      if (email.find('+') != string::npos) 
          email.erase(email.begin() + email.find('+'), email.begin() + email.find('@'));
      email.erase(
        remove(email.begin(), email.begin() + email.find('@'), '.'),
        email.begin() + email.find('@')
      );
      result.insert(email);
    }
    return result.size();
  }
};

int main(void) {
  Solution sol;
  sol.numUniqueEmails({"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"});
  return 0;
}
