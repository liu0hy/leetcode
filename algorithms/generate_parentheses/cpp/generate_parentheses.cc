// https://leetcode.com/problems/generate-parentheses/
class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> ret;
    const string s{"("};
    impl(n, s, 1, 0, ret);
    return ret;
  }

 private:
  void impl(int n, string s, int usedL, int usedR, vector<string> &ret) {
    if (usedL == n) {
      s.append(n - usedR, ')');
      ret.push_back(s);
    } else {
      s.append("(");
      impl(n, s, usedL + 1, usedR, ret);
      if (usedL > usedR) {
        s.back() = ')';
        impl(n, s, usedL, usedR + 1, ret);
      }
    }
  }
};
