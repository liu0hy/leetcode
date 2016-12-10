// https://leetcode.com/problems/regular-expression-matching/
class Solution {
 public:
  bool isMatch(string s, string p) {
    const size_t s_len = s.size();
    const size_t p_len = p.size();
    bool dp[s_len + 1][p_len + 1];
    dp[0][0] = true;
    for (size_t i = 1; i <= s_len; ++i) dp[i][0] = false;
    dp[0][1] = false;
    for (size_t j = 2; j <= p_len; ++j)
      dp[0][j] = (p[j - 1] == '*' && dp[0][j - 2]);
    for (size_t i = 1; i <= s_len; ++i) {
      for (size_t j = 1; j <= p_len; ++j) {
        if (p[j - 1] != '*')
          dp[i][j] =
              ((p[j - 1] == '.' || p[j - 1] == s[i - 1]) && dp[i - 1][j - 1]);
        else
          dp[i][j] =
              (((p[j - 2] == '.' || p[j - 2] == s[i - 1]) && dp[i - 1][j]) ||
               dp[i][j - 2]);
      }
    }
    return dp[s_len][p_len];
  }
};
