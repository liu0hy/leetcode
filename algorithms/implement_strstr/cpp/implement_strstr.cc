// https://leetcode.com/problems/implement-strstr/
class Solution {
 public:
  int strStr(string haystack, string needle) {
    const int m = haystack.size();
    const int n = needle.size();
    for (int i = 0; i < m - n + 1; ++i) {
      size_t k = 0;
      for (; k != n; ++k) {
        if (haystack[i + k] != needle[k]) break;
      }
      if (k == n) return i;
    }
    return -1;
  }
};
