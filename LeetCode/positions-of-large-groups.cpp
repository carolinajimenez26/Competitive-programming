/*
In a string S of lowercase letters, these letters form consecutive 
groups of the same character.

For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", 
"xxxx", "z" and "yy".

Call a group large if it has 3 or more characters.  We would like the 
starting and ending positions of every large group.

The final answer should be in lexicographic order.

Problem source: https://leetcode.com/problems/positions-of-large-groups/description/
*/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#define dbg(x) cout << #x << ": " << x << endl

using namespace std;

void print(vector<vector<int>> vvi) {
    for (auto vi : vvi) {
        for (auto i : vi) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<int>> largeGroupPositions(string S) {
    vector<vector<int>> sol;

    int start = 0, end = 0;
    char curr_char = S[0];
    int i = 1;
    for (; i < S.size(); i++) {
        if (S[i] == curr_char) {
            end++;
        } else {
            if ((end - start) >= 2) {
                sol.push_back({start,end});
            }
            start = end = i;
            curr_char = S[i];
        }
    }

    if ((end - start) >= 2) {
        sol.push_back({start,end});
    }

    return sol;
}

int main(void) {
    vector<string> input = {
        "abbxxxxzzy",
        "abc",
        "abcdddeeeeaabbbcd",
        "eeaeeea",
        "",
        "bbbaaa"
    };

    vector<vector<vector<int>>> expected = {
        {{3,6}},
        {},
        {{3,5},{6,9},{12,14}},
        {{3,5}},
        {},
        {{0,2},{3,5}}
    };

    bool succeed = true;

    for (int i = 0; i < input.size(); i++) {
        vector<vector<int>> output = largeGroupPositions(input[i]);
        if (output == expected[i]) {
            cout << "Succeed" << endl;
        } else {
            cout << "Failure" << endl;
            cout << "Expected " << endl;
            print(expected[i]);
            cout << "Received " << endl;
            print(output);
            succeed = false;
        }
    }

    if (succeed) {
        cout << "Good job" << endl;
    }

    return 0;
}