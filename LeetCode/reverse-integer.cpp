/*
Given a 32-bit signed integer, reverse digits of an integer.
Assume we are dealing with an environment which could only store 
integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. 
For the purpose of this problem, assume that your function returns 0 
when the reversed integer overflows.

Problem source: https://leetcode.com/problems/reverse-integer/
*/
#include <iostream>
#include<string>
#include<vector>
#include <math.h>

using namespace std;

void print(vector<int> v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int reverse(int x) {
    long int sol = 0;
    vector<int> v;
    bool negative = false;

    if (x < 0) {
        x *= -1;
        negative = true;
    }

    while (x != 0) {
        int res = x % 10; // extract all digits
        x = x / 10;
        v.push_back(res);
    }
    // print(v);

    int j = 0;
    for (int i = v.size() - 1; i >= 0; i--) {
        if (v[i] != 0) {
            sol += pow(10, j) * v[i];
        }
        j++;
    }

    if (negative) {
        sol *= -1;
    }

    if (sol < pow(-2,31)) {
        return 0;
    }
    if (sol > (pow(2,31) - 1)) {
        return 0;
    }
    return sol;
}

int main(void) {
    vector<int> input = {
        123,
        -123,
        120,
        300
    };

    vector<int> expected = {
        321,
        -321,
        21,
        3
    };

    bool succeed = true;

    for (int i = 0; i < input.size(); i++) {
        int output = reverse(input[i]);
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