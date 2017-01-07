// https://leetcode.com/problems/divide-two-integers/
class Solution {
 public:
  int divide(int dividend, int divisor) {
    constexpr int maxVal = numeric_limits<int>::max();
    constexpr int minVal = numeric_limits<int>::min();
    if (divisor == 0)
      return maxVal;
    else if (divisor == 1)
      return dividend;
    else if (divisor == -1)
      return dividend == minVal ? maxVal : -dividend;
    bool nega = false;
    int ret = 0;
    if (divisor < 0) {
      if (divisor == minVal) return dividend == minVal ? 1 : 0;
      divisor = -divisor;
      nega = !nega;
    }
    if (dividend < 0) {
      if (dividend == minVal) {
        dividend += divisor;
        ++ret;
      }
      dividend = -dividend;
      nega = !nega;
    }

    int newDivisor = divisor;
    int multiple = 1;
    while (newDivisor <= (dividend >> 1)) {
      newDivisor <<= 1;
      multiple <<= 1;
    }

    while (dividend >= divisor) {
      while (newDivisor > dividend) {
        newDivisor >>= 1;
        multiple >>= 1;
      }

      dividend -= newDivisor;
      ret += multiple;
    }

    return nega ? -ret : ret;
  }
};
