// https://leetcode.com/problems/substring-with-concatenation-of-all-words/
class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    if (s.empty() || words.empty()) return {};
    const int word_len{words.begin()->size()};
    const int words_num{words.size()};
    const int str_len{s.size()};
    if (str_len < word_len * words_num) return {};
    unordered_map<string, int> expect;
    unordered_map<string, int> meet;
    for (auto& w : words) ++expect[w];
    int matched{0};
    auto reset = [&meet, &matched]() {
      matched = 0;
      meet.clear();
    };
    vector<int> ret;
    int start;
    for (int i = 0; i < word_len; ++i) {
      reset();
      const int end{i + (str_len - i) / word_len * word_len};
      for (int k = i; k < end; k += word_len) {
        const string word{s.substr(k, word_len)};
        if (expect[word] == 0)
          reset();
        else {
          if (meet[word] == expect[word]) {
            while (start < k) {
              const string w{s.substr(start, word_len)};
              start += word_len;
              if (w == word) break;
              --meet[w];
              --matched;
            }
          } else {
            ++meet[word];
            if (matched == 0) start = k;
            if (++matched == words_num) {
              ret.push_back(start);
              --meet[s.substr(start, word_len)];
              start += word_len;
              --matched;
            }
          }
        }
      }
    }
    return ret;
  }
};
