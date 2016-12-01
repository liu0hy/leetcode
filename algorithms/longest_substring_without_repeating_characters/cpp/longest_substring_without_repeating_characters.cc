// https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> pos(128, -1);
        int max = 0;
        int len = 0;
        int beg = 0;
        for (int i=0; i!=s.length(); ++i) {
            int& dist = pos[s[i]];
            if (dist>=beg) {
                len -= (dist-beg);
                beg = dist+1;
            } else {
                if (++len>max) max = len;
            }
            dist = i;
        }
        return max;
    }
};
