// https://leetcode.com/problems/reverse-integer/
class Solution {
 public:
  int reverse(int x) {
    int ret = 0;
    const int max_q = numeric_limits<int>::max() / 10;
    const int min_q = numeric_limits<int>::min() / 10;
    const int max_r = numeric_limits<int>::max() % 10;
    const int min_r = numeric_limits<int>::min() % 10;
    while (x) {
      if (ret < min_q || (ret == min_q && x % 10 < min_r)) return 0;
      if (ret > max_q || (ret == max_q && x % 10 > max_r)) return 0;
      ret = ret * 10 + x % 10;
      x /= 10;
    }
    return ret;
  }
};
