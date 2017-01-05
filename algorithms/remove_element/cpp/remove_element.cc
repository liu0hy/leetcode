// https://leetcode.com/problems/remove-element/
class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    size_t i = 0, k = nums.size();
    while (i < k) {
      if (nums[i] == val)
        nums[i] = nums[--k];
      else
        ++i;
    }
    return k;
  }
};
