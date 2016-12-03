// https://leetcode.com/problems/median-of-two-sorted-arrays/
class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.empty() && nums2.empty()) return 0;
    if (nums1.size() > nums2.size()) swap(nums1, nums2);
    size_t half_len = (nums1.size() + nums2.size() + 1) / 2;
    size_t low = 0;
    size_t high = nums1.size();
    size_t i, j;
    while (low <= high) {
      i = low + (high - low) / 2;
      j = half_len - i;
      if (i < nums1.size() && nums1[i] < nums2[j - 1])
        low = i + 1;
      else if (i > 0 && nums1[i - 1] > nums2[j])
        high = i - 1;
      else {
        if (i == 0)
          low = nums2[j - 1];
        else if (j == 0)
          low = nums1[i - 1];
        else
          low = max(nums1[i - 1], nums2[j - 1]);
        bool even = (nums1.size() + nums2.size()) % 2 == 0;
        if (!even) return low;
        if (i == nums1.size())
          high = nums2[j];
        else if (j == nums2.size())
          high = nums1[0];
        else
          high = min(nums1[i], nums2[j]);
        return high / 2.0 + low / 2.0;
      }
    }
    return 0;
  }
};
