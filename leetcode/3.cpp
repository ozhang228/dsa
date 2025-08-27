#include <bits/stdc++.h>
using namespace std;

struct pair_hash {
  inline std::size_t operator()(const std::pair<int, int> &v) const {
    return v.first * 31 + v.second;
  }
};

/**
set + sliding window

**/

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int l = 0;
    unordered_set<char> visited{};
    int maxLen = 0;

    for (int r = 0; r < s.size(); ++r) {
      while (visited.find(s[r]) != visited.end()) {
        visited.erase(s[l]);
        l++;
      }
      visited.insert(s[r]);

      maxLen = max(r - l + 1, maxLen);
    }
    return maxLen;
  }
};
