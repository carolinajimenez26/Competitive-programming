#include <iostream>
#include <string>
#include <set>
#define endl '\n'

using namespace std;

struct classcomp {
  bool operator() (const pair<char, int>& lhs, const pair<char, int>& rhs) const
  {return lhs.first > rhs.first;}
};

pair<int, int> haveSubLess(string& s) {
    set<pair<char, int>, classcomp> visited; // char, index
    visited.insert({ s[0], 0 });
    for (int i = 1; i < s.size(); i++) {
        auto e = *visited.begin();
        if (e.first > s[i]) {
            return {e.second, i};
        }
        visited.insert({ s[i], i });
    }
    return {-1, -1};
}

int main(int argc, char const *argv[]) {
    int n;
    char c;
    string s = "";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c;
        s.push_back(c);
    }
    // dbg(s);
    pair<int, int> result = haveSubLess(s);
    if (result.first == -1) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        cout << (result.first + 1) << " " << (result.second + 1) << endl;
    }
    return 0;
}
