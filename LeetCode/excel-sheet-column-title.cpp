/*
Given a positive integer, return its corresponding column title as 
appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
    ...

Problem source: https://leetcode.com/problems/excel-sheet-column-title/
*/

#include <iostream>
#include <vector>
#include <string> 
#include <stack>
#define dbg(x) cout << #x << ": " << x << endl

using namespace std;

string convertToTitle(int n) {
    vector<char> alphabet = {
        'A','B','C','D','E','F','G','H','I','J','K','L','M','N',
        'O','P','Q','R','S','T','U','V','W','X','Y','Z'
    };
    stack<char> ssol;
    string sol = "";
    int res = 0;
    bool z = false;

    while(n != 0) {
        res = n % 26;
        // dbg(res); dbg(z);
        if (res == 0) {
            z = true;
            ssol.push(alphabet[25]);
            if (n / 26 == 1) break;
        } else {
            if (z) {
                if (res == 1) ssol.push(alphabet[25]);
                else ssol.push(alphabet[res - 2]);
                if (n / 26 == 1) break;
                z = false;
            } else ssol.push(alphabet[res - 1]);
        }
        n /= 26;
        // dbg(n);
    }

    while(!ssol.empty()) {
        sol.push_back(ssol.top());
        ssol.pop();
    }

    return sol;
}

int main(void) {

    vector<int> input = {
        2147483647,
        1,
        2600,
        78,
        104,
        105,
        26,
        27,
        28,
        702
    };

    vector<string> expected = {
        "FXSHRXW",
        "A",
        "CUZ",
        "BZ",
        "CZ",
        "DA",
        "Z",
        "AA",
        "AB",
        "ZZ"
    };

    bool succeed = true;

    for (int i = 0; i < input.size(); i++) {
        string output = convertToTitle(input[i]);
        if (output == expected[i]) {
            cout << "Succeed" << endl;
        } else {
            cout << "Failure" << endl;
            cout << "Expected " << expected[i] << endl;
            cout << "Received " << output << endl;
            succeed = false;
        }
    }

    if (succeed) {
        cout << "Good job" << endl;
    }

    return 0;
}