#include <iostream>
#include <unordered_map>

#define dbg(x) cout << #x << ": " << (x) << endl

using namespace std;

void print(unordered_map<char,char>& f) {
    for (auto e : f) {
        cout << e.first << " -> " << e.second << endl;
    }
    cout << endl;
}

string maximize(const string& s, unordered_map<char,char>& f) {
    string result = s;
    bool flag = false;
    for (int i = 0; i < s.size(); i++) {
        char c = f[s[i]];
        if (s[i] <= c) {
            result[i] = c;
            flag = flag || (s[i] < c);
        } else {
           if (flag) break;
        }
    }
    return result;
}

int main(void) {
    int n;
    char c;
    string nums;
    cin >> n;
    cin >> nums;
    unordered_map<char, char> f(10);
    
    f['0'] = '0';
    
    char i_c = '1';
    for (int i = 1; i < 10; i++) {
        cin >> c;
        f[i_c] = c;
        i_c++;
    }

    // print(f);

    string result = maximize(nums, f);
    cout << result << endl;
    return 0;
}