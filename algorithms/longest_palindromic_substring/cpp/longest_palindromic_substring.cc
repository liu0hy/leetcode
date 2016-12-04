// https://leetcode.com/problems/longest-palindromic-substring/
class Solution {
 public:
  string longestPalindrome(string s) {
    if (s.size() < 2) return s;
    size_t maxLen = 1;
    size_t maxBeg = 0;
    const size_t len = s.size();
    size_t beg, end;
    for (size_t i = 0; i != len;) {
      beg = end = i;
      while (end + 1 < len && s[end + 1] == s[i]) ++end;
      i = end + 1;
      while (beg > 0 && end + 1 < len && s[beg - 1] == s[end + 1]) {
        --beg;
        ++end;
      }
      if (end - beg + 1 > maxLen) {
        maxBeg = beg;
        maxLen = end - beg + 1;
      }
      if (2 * (len - i) - 1 <= maxLen) break;
    }
    return s.substr(maxBeg, maxLen);
  }
};
