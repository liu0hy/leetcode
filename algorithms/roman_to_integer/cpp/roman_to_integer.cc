// https://leetcode.com/problems/roman-to-integer/
class Solution {
 public:
  int romanToInt(string s) {
    int digits[128];
    digits['I'] = 1;
    digits['V'] = 5;
    digits['X'] = 10;
    digits['L'] = 50;
    digits['C'] = 100;
    digits['D'] = 500;
    digits['M'] = 1000;
    const char* beg = s.c_str();
    const char* pos = beg + s.length() - 1;
    int pre = digits[*pos];
    int cur;
    int integer = pre;
    while (--pos >= beg) {
      cur = digits[*pos];
      if (cur < pre)
        integer -= cur;
      else
        integer += cur;
      pre = cur;
    }
    return integer;
  }
};
