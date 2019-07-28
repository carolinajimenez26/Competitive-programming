/*
In a deck of cards, each card has an integer written on it.
Return true if and only if you can choose X >= 2 such that it is 
possible to split the entire deck into 1 or more groups of cards, where:
    Each group has exactly X cards.
    All the cards in each group have the same integer.

Problem source: https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/
*/

#include<iostream>
#include<vector>
#include<map>
#include <limits>

using namespace std;

void print(map<int, int> m) {
    for (auto e : m) {
        cout << e.first << "->" << e.second << endl;
    }
}

int gcd(int a, int b) {
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
}

bool hasGroupsSizeX(vector<int>& deck) {

    if (deck.size() <= 1) return false;

    map<int, int> frec; // value, times

    for (auto e : deck) {
        if (frec.count(e)) {
            frec[e]++;
        } else {
            frec[e] = 1;
        }
    }
    // print(frec);

    if (frec.size() == 1) return true;

    int curr_gcd, prev_gcd;
    auto j = frec.begin(), i = frec.begin();
    ++j;
    prev_gcd = gcd(i->second, j->second);
    if (prev_gcd == 1) return false;
    ++j; ++i;
    if (j == frec.end()) return true;

    while (j != frec.end()) {
        curr_gcd = gcd(prev_gcd, j->second);
        if (curr_gcd == 1) return false;
        prev_gcd = curr_gcd;
        ++j;
    }
    if (curr_gcd == 1) return false;
    return true;
}

int main(void) {
    vector<vector<int> > input = {
        {1,2,3,4,4,3,2,1},
        {1,1,1,2,2,2,3,3},
        {1},
        {1,1},
        {1,1,2,2,2,2},
        {1,1,1,1,2,2,2,2,2,2},
        {0,0,0,0,0,0,0,1,2,3,3,3,4,5,6},
        {0,0,0,1,1,1,1,1,1,2,2,2,3,3,3}
    };

    vector<bool> expected = {
        true,
        false,
        false,
        true,
        true,
        true,
        false,
        true
    };

    bool succeed = true;

    for (int i = 0; i < input.size(); i++) {
        bool sol = hasGroupsSizeX(input[i]);
        if (sol == expected[i]) {
            cout << "Succeed" << endl;
        } else {
            cout << "Failure" << endl;
            succeed = false;
            cout << "Expected: " << expected[i] << endl;
            cout << "Received: " << sol << endl;
        }
    }

    if (succeed) {
        cout << "Good job" << endl;
    } else {
        cout << "Keep trying" << endl;
    }

    return 0;
}