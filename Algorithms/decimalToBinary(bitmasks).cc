#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<vector>
using namespace std;

int main(void){
    int hexa_number = 0;
    vector<int> binary;
    unsigned num_bits = 4;
    unsigned bitmask = 1 << (num_bits - 1); // 2 ^ 31
    cout << "Enter a number in hexadecimal form: ";
    cin >> hexa_number;

    unsigned num_ones = 0;
    unsigned num_zeros = 0;

    cout << "bitmask : " << bitmask << endl;

    for(int k = 0; k < num_bits; k ++) {
      cout << "bitmask >> k : " << (bitmask >> k) << endl;
        if(hexa_number & (bitmask >> k)) {
            binary.push_back(1);
            num_ones ++;
        }
        else {
            binary.push_back(0);
            num_zeros++;
        }
    }
    cout << endl << "Number of ones is " << num_ones << " number of zeros is " << num_zeros << endl;

    for (int i = 0; i < binary.size(); i++) {
      cout << binary[i] << " ";
    }
    return 0;
}
