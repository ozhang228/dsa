#include <bits/stdc++.h>
using namespace std;

struct pair_hash {
  inline std::size_t operator()(const std::pair<int, int> &v) const {
    return v.first * 31 + v.second;
  }
};

/**

The idea here is that by starting at the ends we have two pointers

for pointer i, j where p_i < p_j;

say that pointer i is smaller or equal to pointer j

the optimal partner of pointer i is pointer j because its the furthest wall that
fully utilizes pointer i. thus we can discard it and move forward

**/

class Solution {
public:
  int maxArea(vector<int> &height) {
    int l = 0;
    int r = height.size() - 1;

    long long ans = 0;

    while (l < r) {
      ans = max(ans, (long long)min(height[l], height[r]) * (r - l));

      if (height[l] <= height[r]) {
        l++;
      } else {
        r--;
      }
    }

    return ans;
  }
};
