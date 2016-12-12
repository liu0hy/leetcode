// https://leetcode.com/problems/integer-to-roman/
static const string one[]{"",  "I",  "II",  "III",  "IV",
                          "V", "VI", "VII", "VIII", "IX"};
static const string ten[]{"",  "X",  "XX",  "XXX",  "XL",
                          "L", "LX", "LXX", "LXXX", "XC"};
static const string hundred[]{"",  "C",  "CC",  "CCC",  "CD",
                              "D", "DC", "DCC", "DCCC", "CM"};
static const string thousand[]{"", "M", "MM", "MMM"};

class Solution {
 public:
  string intToRoman(int num) {
    return thousand[num / 1000] + hundred[num / 100 % 10] + ten[num / 10 % 10] +
           one[num % 10];
  }
};
