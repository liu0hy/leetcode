// https://leetcode.com/problems/string-to-integer-atoi/
class Solution {
 public:
  int myAtoi(string str) {
    size_t pos = 0;
    const size_t len = str.length();
    while (pos != len && str[pos] == ' ') ++pos;
    if (pos == len) return 0;
    int factor = 1;
    if (str[pos] == '-' || str[pos] == '+') factor = str[pos++] == '-' ? -1 : 1;
    int result = 0;
    const int max_q = numeric_limits<int>::max() / 10;
    const int max_r = numeric_limits<int>::max() % 10;
    const int min_q = numeric_limits<int>::min() / 10;
    const int min_r = numeric_limits<int>::min() % 10;
    while (pos != len && str[pos] >= '0' && str[pos] <= '9') {
      if (result > max_q || (result == max_q && str[pos] - '0' > max_r))
        return numeric_limits<int>::max();
      if (result < min_q || (result == min_q && str[pos] - '0' > -min_r))
        return numeric_limits<int>::min();
      result = result * 10 + factor * (str[pos++] - '0');
    }
    return result;
  }
};
