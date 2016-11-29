// https://leetcode.com/problems/two-sum/

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, size_t> m;
    for (size_t i = 0; i != nums.size(); ++i) {
      if (m.end() == m.find(target - nums[i])) {
        m.insert(make_pair(nums[i], i));
      } else {
        return {m.at(target - nums[i]), i};
      }
    }
    return {-1, -1};
  }
};
