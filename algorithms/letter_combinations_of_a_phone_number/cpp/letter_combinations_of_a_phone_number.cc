// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    static const vector<string> letters{"abc", "def",  "ghi", "jkl",
                                        "mno", "pqrs", "tuv", "wxyz"};
    if (digits.empty()) return {};
    vector<size_t> offsets(digits.size());
    for (size_t i = 0; i != digits.size(); ++i) offsets[i] = digits[i] - '2';
    const size_t len = accumulate(offsets.begin(), offsets.end(), 1,
                                  [&letters](size_t lhs, size_t rhs) {
                                    return lhs * letters[rhs].size();
                                  });
    vector<string> result(len, digits);
    size_t cycle = 1, repeat, multi;
    for (size_t i = 0; i != digits.size(); ++i) {
      multi = letters[offsets[i]].size();
      for (size_t j = 0; j != cycle; ++j) {
        repeat = len / cycle / multi;
        for (size_t k = 0; k != len / cycle; ++k) {
          result[j * len / cycle + k][i] = letters[offsets[i]][k / repeat];
        }
      }
      cycle *= multi;
    }
    return result;
  }
};
