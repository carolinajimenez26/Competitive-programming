#include <iostream>
#include <unordered_map>
#define dbg(x) cout << #x << ": " << x << endl

using namespace std;

class Solution {
private:
  unordered_map<int, string> num_to_roman = {
    {1, "I"},
    {4, "IV"},
    {5, "V"},
    {9, "IX"},
    {10, "X"},
    {40, "XL"},
    {50, "L"},
    {90, "XC"},
    {100, "C"},
    {400, "CD"},
    {500, "D"},
    {900, "CM"},
    {1000, "M"}
  };

  string Convert(int num) {
    string result;
    if (num >= 5) {
      result += "V";
      num -= 5;
    }
    if (num == 4) {
      result += "IV";
      num -= 4;
    }
    while (num > 0) {
      result += "I";
      num--;
    }
    return result;
  }

  string Convert(int times, int key, int num) {
    string result;
    if (num_to_roman.count(num) != 0) {
      return num_to_roman[num];
    }
    if (num >= 60 && num <= 80) {
      result += "L";
      num -= 50;
      times -= 5;
    }
    if (num >= 600 && num <= 800) {
      result += "D";
      num -= 500;
      times -= 5;
    }
    for (int i = 0; i < times; i++) {
      result += num_to_roman[key];
    }
    return result;
  }

  int FirstDigit(int num) {
    while (num >= 10) {
      num /= 10;
    }
    return num;
  }

public:
  string intToRoman(int num) {
    int next;
    string result;
    while (num >= 9) {
      int first_digit = FirstDigit(num);
      int power = pow(10, int(log10(num)));
      int tmp = power * first_digit;
      int next = num - tmp;
      num -= next;
      result += Convert(first_digit, power, num);
      num = next;
    }
    result += Convert(num);
    return result;
  }
};

int main(void) {
  Solution sol;
  int n = 600;
  cout << sol.intToRoman(n) << endl;
  return 0;
}