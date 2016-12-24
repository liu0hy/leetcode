// https://leetcode.com/problems/3sum-closest/
class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    int result = nums[0] + nums[1] + nums[2];
    int diff = result > target ? result - target : target - result;
    sort(nums.begin(), nums.end());
    int sum;
    size_t second, third;
    const size_t len = nums.size();
    for (size_t first = 0; first < len - 2; ++first) {
      second = first + 1;
      third = len - 1;
      while (second < third) {
        sum = nums[first] + nums[second] + nums[third];
        if (sum < target) {
          if (target - sum < diff) {
            result = sum;
            diff = target - sum;
          }
          ++second;
          while (second < third && nums[second - 1] == nums[second]) ++second;
        } else if (sum > target) {
          if (sum - target < diff) {
            result = sum;
            diff = sum - target;
          }
          --third;
          while (second < third && nums[third + 1] == nums[third]) --third;
        } else {
          return target;
        }
      }
      while (first < len - 3 && nums[first + 1] == nums[first]) ++first;
    }
    return result;
  }
};
