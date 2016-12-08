// https://leetcode.com/problems/palindrome-number/
class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;
    else if (x < 10)
      return true;
    else if (x % 10 == 0)
      return false;
    int len = 10;
    while (x / len >= 10) len *= 10;
    while (x) {
      if (x / len != x % 10) return false;
      x = (x % len) / 10;
      len /= 100;
    }
    return true;
  }
};
