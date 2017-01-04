// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    const size_t len = nums.size();
    if (len < 2) return len;
    size_t k = 1;
    for (size_t i = 1; i != len; ++i) {
      if (nums[i] != nums[k - 1]) nums[k++] = nums[i];
    }
    return k;
  }
};
