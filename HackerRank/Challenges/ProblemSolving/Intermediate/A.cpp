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
int64 FastPow(int x, unsigned int p) {
  if (p == 0) return 1;
  if (p == 1) return x;
  
  int64 tmp = FastPow(x, p/2);
  if (p % 2 == 0) return tmp * tmp;
  return x * tmp * tmp;
}

class PasswordManager {
public:
  PasswordManager() {}

  void SetPassword(const string& desired_password) {
    password = desired_password;
    allowed_passwords.clear();
    
    if (cache.count(password) > 0) {
      allowed_passwords = cache[password];
      return;
    }

    allowed_passwords.insert(hashFunction(password));
    for (int i = 0; i <= 127; i++) {
      char c = i;
      string s = password + c;
      allowed_passwords.insert(hashFunction(s));
    }

    cache[password] = allowed_passwords;
  }

  bool Authorize(int input_password) {
    return allowed_passwords.count(input_password) > 0;
  }

  void Print() {
    for (auto allowed_password : allowed_passwords) {
      cout << allowed_password << ",";
    }
    cout << endl;
  }

private:
  string password;
  unordered_set<int> allowed_passwords;
  unordered_map<string, unordered_set<int>> cache;
  const int P = 131;
  const int M = 1e9 + 7;

  int hashFunction(const string& s) {
    int n = s.size();
    int64 result = 0;
    
    int i = n - 1;
    for (auto c : s) {
      int ascii_to_int = c;
      int64 exp = FastPow(P, i) % M;
      int64 partial = (ascii_to_int * exp) % M;
      result += (partial % M);
      i--;
    }
    return result;
  }
};

vector<int> authEvents(vector<vector<string>> events) {
  PasswordManager password_manager;
  vector<int> result;
  for (auto event : events) {
    string eventType = event[0];
    string password = event[1];
    if (eventType == "setPassword") {
      password_manager.SetPassword(password);
      // password_manager.Print();
    } else {
      int password_hash = stoi(password);
      result.push_back(password_manager.Authorize(password_hash));
    }
  }
  return result;
}

struct Test {
  vector<vector<string>> events;
  vector<int> expected;
};

void Print(const vector<int>& v) {
  for (auto e : v) cout << e << " ";
  cout << endl;
}

int main(void) {
  vector<Test> tests = {
    {
      {
        {"setPassword", "1"},
        {"setPassword", "2"},
        {"setPassword", "3"},
        {"authorize", "49"},
        {"authorize", "50"},
      },
      {0,0}
    },
    {
      {
        {"setPassword", "cAr1"},
        {"setPassword", "2"},
        {"setPassword", "3"},
        {"authorize", "49"},
        {"authorize", "50"},
        {"setPassword", "cAr1"},
        {"authorize", "223691457"},
      },
      {0,0,1}
    },
  };
  int tc = 0;
  bool succeed = true;
  for (auto test : tests) {
    vector<int> out = authEvents(test.events); 
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