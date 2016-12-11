// https://leetcode.com/problems/container-with-most-water/
class Solution {
 public:
  int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int capacity = 0;
    int short_side = 0;
    while (left < right) {
      short_side = min(height[left], height[right]);
      capacity = max(capacity, short_side * (right - left));
      while (height[left] <= short_side && left < right) ++left;
      while (height[right] <= short_side && right > left) --right;
    }
    return capacity;
  }
};
