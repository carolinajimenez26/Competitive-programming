#include <iostream>
#include <vector>
#include <set>
#include <string>
#define dbg(x) cout << #x << ": " << (x) << endl
using namespace std;

void closeRest(string& s, int x) {
    for (int i = 0; i < x; i++) {
        s.push_back(')');
    }
}

bool isValid(string& s) {
    int open = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') open++;
        else {
            if (open == 0) return false;
            else open--;
        }
    }
    return open == 0;
}

void generate(string s, int open_used, int close_used, set<string>& results,
              int max) {
    if (open_used == max || close_used == max) {
        closeRest(s, max - close_used);
        if (isValid(s)) results.insert(s);
    } else {
        s.push_back('(');
        generate(s, open_used + 1, close_used, results, max);
        s.pop_back();
        s.push_back(')');
        generate(s, open_used, close_used + 1, results, max);
    }
}

vector<string> generateParenthesis(int n) {
    set<string> results;
    string s = "";
    int open_used = 0, close_used = 0;
    generate(s, open_used, close_used, results, n);
    vector<string> result(results.begin(), results.end());
    return result;
}

int main(void) {
    vector<string> output = generateParenthesis(3);
    return 0;
}
