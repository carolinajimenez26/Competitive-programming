/*
Given two strings A and B of lowercase letters, return true if and 
only if we can swap two letters in A so that the result equals B.

Problem source: https://leetcode.com/problems/buddy-strings/
*/

#include <iostream>
#include <vector>
#include <string> 
#include <map> 
#include <algorithm>
#define dbg(x) cout << #x << ": " << x << endl

using namespace std;

void print(map<char, vector<int> > m) {
    for (auto e : m) {
        cout << e.first << " -> ";
        for (auto i : e.second) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}

string swap(string A, int i, int j) {
    string tmp = A;
    tmp[i] = A[j];
    tmp[j] = A[i];
    return tmp;
}

bool repeatedChar(map<char, vector<int> > frec) {
    for (auto e : frec) {
        // return true if there is at least one char repeted
        if (e.second.size() > 1) {
            return true;
        }
    }
    return false;
}

map<char, vector<int> > getFrecuency(string s) {
    map<char, vector<int> > frec;
    for (int i = 0; i < s.size(); i++) {
        frec[s[i]].push_back(i);
    }
    return frec;
}

bool buddyStringsHandler(string A, string B, int idx,
                         map<char, vector<int> > frecA, 
                         map<char, vector<int> > frecB) {

    vector<int> v = frecA[B[idx]]; // where is char B[idx] in string A
    for (auto i : v) { // iterate all the posibles indexes to swap
        if (A[i] != B[i]) {
            B = swap(B, idx, i);
            return A == B;
        }
    }
}

bool sameFrecuency(map<char, vector<int> > frecA, 
                   map<char, vector<int> > frecB) {
    
    auto j = frecB.begin();
    for (auto i : frecA) {
        if (i.first != j->first) return false;
        if (i.second.size() != j->second.size()) return false;
        ++j;
    }
    return true;
}

bool buddyStrings(string A, string B) {
    if (A.size() < 2 || B.size() < 2) return false;
    if (A.size() != B.size()) return false;

    map<char, vector<int> > frecA = getFrecuency(A);

    if (A == B) {
        if (frecA.size() == 1) { // is the same char in the string
            return true;
        }
        if (A.size() > 2 && repeatedChar(frecA)) return true;
        return false;
    }

    map<char, vector<int> > frecB = getFrecuency(B);
    // print(frecA); print(frecB);
    if (!sameFrecuency(frecA, frecB)) return false;

    for (int i = 0; i < A.size(); i++) {
        if (A[i] != B[i]) {
            return buddyStringsHandler(A, B, i, frecA, frecB);
        }
    }
}

int main(void) {
    vector<string> input_a = {
        "ab",
        "ab",
        "aa",
        "aaaaaaabc",
        "",
        "",
        "aaabc",
        "aaab",
        "abab",
        "a",
        "abcd",
        "ab"
    };

    vector<string> input_b = {
        "ba",
        "ab",
        "aa",
        "aaaaaaacb",
        "aa",
        "",
        "bcaaa",
        "baaa",
        "abab",
        "a",
        "abcd",
        "ca"
    };

    vector<bool> expected = {
        true,
        false,
        true,
        true,
        false,
        false,
        false,
        true,
        true,
        false,
        false,
        false
    };

    bool succeed = true;

    for (int i = 0; i < input_a.size(); i++) {
        bool output = buddyStrings(input_a[i], input_b[i]);
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