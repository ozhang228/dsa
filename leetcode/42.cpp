#include <bits/stdc++.h>
using namespace std;

struct pair_hash {
  inline std::size_t operator()(const std::pair<int, int> &v) const {
    return v.first * 31 + v.second;
  }
};

void printvi(vector<int> v) {
  printf("[");

  for (int i = 0; i < v.size(); ++i) {
    printf("%d", v[i]);

    if (i != v.size() - 1) {
      printf(",");
    }
  }
  printf("]");
}

/**
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105
**/

class Solution {
public:
    int trap(vector<int>& height) {
      vector<int> left_max(height.size(), 0);
      vector<int> right_max(height.size(), 0);

      int maxHeight = 0;
      for (int i = 0; i < height.size(); ++i) {
        left_max[i] = maxHeight;
        maxHeight = max(maxHeight, height[i]);
      }

      maxHeight = 0;
      for (int i = height.size() - 1; i >= 0; --i) {
        right_max[i] = maxHeight;
        maxHeight = max(maxHeight, height[i]);
      }
      
      printvi(left_max);
      printvi(right_max);
      
      int totalWater{};

      for (int i = 0; i < height.size(); ++i) {
        totalWater += max(0, min(left_max[i], right_max[i]) - height[i]);
      }

      return totalWater;
    }
};
