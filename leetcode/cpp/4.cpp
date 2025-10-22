#include <bits/stdc++.h>
#include <cassert>
#include <utility>
using namespace std;
/**
  Problem:
  sorted arrays nums1 and nums2
  find the median of the two arrays with O(log(m + n))

  this means binary search must likely

  two cases:
    (m + n) % 2 == 0
      - (mid1 + mid2) / 2
    (m + n) % 2 == 1
      - there will be a number that is the median

  so we know that the (len / 2) will either be the median or part of it

  we can binary search in nums1 which corresponds to a val in nums2

  for an arbritary i
  nums2[i] and nums2[(len / 2) - (i + 2)]
  (if -1) then assume its always less

  if both are less then one of them must be the median
  the bigger one is the median, if its odd then return that
  else return the minimum of the other
**/

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int len = (nums1.size() + nums2.size());
    // nums1 always the smaller one for consistency
    if (nums1.size() > nums2.size()) {
      swap(nums1, nums2);
    }
    // if nums1 size is 0 then just return median of the other
    if (nums1.size() == 0) {
      if (nums2.size() == 1) {
        return nums2[0];
      }
      return len % 2 == 1 ? nums2[len / 2]
                          : (nums2[len / 2] + nums2[len / 2 + 1] / 2.0);
    }

    int l = -1;
    int r = nums1.size() - 1;

    while (l <= r) {
      int idx1 = l + (r - l) / 2;
      int idx2 = ceil(len / 2.0) - (idx1 + 2);
      printf("%d %d %d %d\n", l, r, idx1, idx2);

      int num1l = idx1 == -1 ? INT_MIN : nums1[idx1];
      int num1r = idx1 + 1 == nums1.size() ? INT_MAX : nums1[idx1 + 1];
      int num2l = idx2 == -1 ? INT_MIN : nums2[idx2];
      int num2r = idx2 + 1 == nums2.size() ? INT_MAX : nums2[idx2 + 1];

      printf("%d %d %d %d\n", num1l, num1r, num2l, num2r);

      if (max(num1l, num2l) <= min(num1r, num2r)) {
        if (len % 2 == 0) {
          return (max(num1l, num2l) + min(num1r, num2r)) / 2.0;
        } else {
          return max(num1l, num2l);
        }
      } else if (num1l > min(num1r, num2r)) {
        r = idx1 - 1;
      } else {
        l = idx1 + 1;
      }
    }

    assert(false);
  }
};

int main() {
  Solution s{};
  vector<int> nums1 = {2, 2, 4, 4};
  vector<int> nums2 = {2, 2, 2, 4, 4};
  printf("%f", s.findMedianSortedArrays(nums1, nums2));
  return 0;
}
