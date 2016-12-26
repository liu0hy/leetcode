// https://leetcode.com/problems/4sum/
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    if (nums.size() < 4) return {};
    sort(nums.begin(), nums.end());
    size_t first, second, third, fourth;
    const size_t len = nums.size();
    vector<vector<int>> result;
    for (first = 0; first < len - 3; ++first) {
      if (nums[first] + nums[len - 1] + nums[len - 2] + nums[len - 3] < target)
        continue;
      if (nums[first] + nums[first + 1] + nums[first + 2] + nums[first + 3] >
          target)
        break;
      for (fourth = len - 1; fourth > first + 2; --fourth) {
        if (nums[first] + nums[fourth - 1] + nums[fourth - 2] + nums[fourth] <
            target)
          break;
        if (nums[first] + nums[first + 1] + nums[first + 2] + nums[fourth] >
            target)
          continue;
        second = first + 1;
        third = fourth - 1;
        while (second < third) {
          int sum = nums[first] + nums[second] + nums[third] + nums[fourth];
          if (sum > target) {
            do {
              --third;
            } while (second < third && nums[third] == nums[third + 1]);
          } else if (sum < target) {
            do {
              ++second;
            } while (second < third && nums[second] == nums[second - 1]);
          } else {
            result.push_back(
                {nums[first], nums[second], nums[third], nums[fourth]});
            do {
              --third;
            } while (second < third && nums[third] == nums[third + 1]);
            do {
              ++second;
            } while (second < third && nums[second] == nums[second - 1]);
          }
        }
        while (fourth > first + 3 && nums[fourth - 1] == nums[fourth]) --fourth;
      }
      while (first < len - 4 && nums[first + 1] == nums[first]) ++first;
    }
    return result;
  }
};
