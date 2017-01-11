// https://leetcode.com/problems/next-permutation/
class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    auto iter = is_sorted_until(nums.rbegin(), nums.rend());
    if (iter != nums.rend())
      iter_swap(iter, upper_bound(nums.rbegin(), iter, *iter));
    reverse(nums.rbegin(), iter);
  }
};
