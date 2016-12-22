// https://leetcode.com/problems/3sum/
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.size() < 3) return {};
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
    const size_t len = nums.size();
    int sum = 0;
    size_t second, third;
    for (size_t first = 0; first < len - 2; ++first) {
      second = first + 1;
      third = len - 1;
      while (second < third) {
        sum = nums[first] + nums[second] + nums[third];
        if (sum > 0)
          --third;
        else if (sum < 0)
          ++second;
        else {
          ret.push_back({nums[first], nums[second++], nums[third--]});
          while (second < third && nums[second - 1] == nums[second]) ++second;
          while (second < third && nums[third + 1] == nums[third]) --third;
        }
      }
      while (first + 1 < len - 2 && nums[first + 1] == nums[first]) ++first;
    }
    return ret;
  }
};
