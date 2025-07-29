#include <bits/stdc++.h>
#include <fmt/ranges.h>
using namespace std;

/**
i is a hill if closest non-equal neighbors are smaller
valley is closest are larger

array of next
pointer to prev
skip those that are the same
**/

class Solution {
public:
  int countHillValley(vector<int> &nums) {
    vector<int> next(nums.size(), -1);

    int prev = nums[nums.size() - 1];
    for (int i = nums.size() - 2; i >= 0; --i) {
      if (nums[i] == nums[i + 1]) {
        next[i] = next[i + 1];
      } else {
        next[i] = prev;
        prev = nums[i];
      }
    }
    int closestDiff = nums[0];
    int ans = 0;

    for (int i = 1; i < nums.size(); ++i) {
      if (next[i] == -1) {
        break;
      }
      if (nums[i] == nums[i - 1]) {
        continue;
      }

      // printf("%d %d, %d\n", nums[i], closestDiff, next[i]);
      if ((next[i] > nums[i] && closestDiff > nums[i]) ||
          (next[i] < nums[i] && closestDiff < nums[i])) {
        ans += 1;
      }
      closestDiff = nums[i];
    }

    return ans;
  }
};

int main() {
  Solution s{};
  vector<int> nums{2, 4, 1, 1, 6, 5};
  printf("%d", s.countHillValley(nums));
  return 0;
}
