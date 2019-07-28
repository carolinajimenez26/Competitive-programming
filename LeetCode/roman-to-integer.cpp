#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, int> getRomanCode() {
    unordered_map<char, int> result;
    result['I'] = 1;
    result['V'] = 5;
    result['X'] = 10;
    result['L'] = 50;
    result['C'] = 100;
    result['D'] = 500;
    result['M'] = 1000;
    return result;
}

bool specialCase(string s, int index) {
    bool result = index + 1 < s.size ();
    if (!result) return false;
    switch (s[index]) {
    case 'I':
        return s[index + 1] == 'V' || s[index + 1] == 'X';
        break;
    case 'X':
        return s[index + 1] == 'L' || s[index + 1] == 'C';
        break;
    case 'C':
        return s[index + 1] == 'D' || s[index + 1] == 'M';
        break;
    default:
        return false;
        break;
    }
}

int romanToInt(string s) {
    int result = 0;
    unordered_map<char, int> roman_code = getRomanCode();
    for (int i = 0; i < s.size();) {
        if (specialCase(s, i)) {
            result += (roman_code[s[i + 1]] - roman_code[s[i]]);
            i += 2;
        } else {
            result += roman_code[s[i]];
            i++;
        }
    }
    return result;
}

int main(int argc, char const *argv[]) {
    return 0;
}
