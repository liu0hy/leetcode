// https://leetcode.com/problems/zigzag-conversion/
class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1 || numRows >= s.length()) return s;
    const int magic = 2 * numRows - 2;
    const int len = s.length();
    string r(s);
    int conv = 0;
    int index, group;
    for (int i = 0; i < numRows; ++i) {
      group = 0;
      while (true) {
        index = (group++) * magic + i;
        if (index >= len) break;
        r[conv++] = s[index];
        if (conv == len) return r;
        if (i == 0 || i == numRows - 1) continue;
        index = group * magic - i;
        if (index >= len) break;
        r[conv++] = s[index];
        if (conv == len) return r;
      }
    }
    return r;
  }
};
