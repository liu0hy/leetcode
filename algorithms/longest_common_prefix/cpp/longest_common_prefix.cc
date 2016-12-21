// https://leetcode.com/problems/longest-common-prefix/
class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    string prefix{strs[0]};
    const size_t vec_len = strs.size();
    size_t beg = prefix.size(), end;
    for (size_t i = 1; i < vec_len; ++i) {
      end = min(strs[i].size(), beg);
      beg = 0;
      while (beg < end && strs[i][beg] == prefix[beg]) ++beg;
      if (beg == 0) return "";
    }
    prefix.resize(beg);
    return prefix;
  }
};
