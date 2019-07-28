/*
Given two strings A and B of lowercase letters, return true if and 
only if we can swap two letters in A so that the result equals B.

Problem source: https://leetcode.com/problems/buddy-strings/
*/

#include <iostream>
#include <vector>
#include <string> 
#include <map>
#define dbg(x) cout << #x << ": " << x << endl

using namespace std;

void print(map<char, int> m) {
    for (auto e : m) {
        cout << e.first << "->" << e.second << endl;
    }
}

int longestPalindrome(string s) {
    map<char, int> frec;
    int longest = 0;
    bool takeOne = false;

    for (auto c : s) {
        if (frec.count(c)) frec[c] += 1;
        else frec[c] = 1;
    }

    // print(frec);

    for (auto e : frec) {
        if (e.second % 2 == 0) longest += e.second; // take it all
        else {
            if ((e.second - 1) % 2 == 0) {
                if (!takeOne) {
                    longest += e.second;
                    takeOne = true;
                } else {
                    longest += e.second - 1;
                }
            } else {
                // e.second is 1
                if (!takeOne) {
                    longest += e.second;
                    takeOne = true;
                }
            }
        }
    }

    return longest;
}

int main(void) {

    vector<string> input = {
        "ba",
        "ab",
        "aa",
        "aaaaaaacb",
        "",
        "bcaaa",
        "baaab",
        "abab",
        "a",
        "abcd",
        "ca",
        "abccccdd",
        "aaabbc",
        "aaaa",
        "aaaAaaaa"
    };

    vector<int> expected = {
        1,
        1,
        2,
        7,
        0,
        3,
        5,
        4,
        1,
        1,
        1,
        7,
        5,
        4,
        7
    };

    bool succeed = true;

    for (int i = 0; i < input.size(); i++) {
        int output = longestPalindrome(input[i]);
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
