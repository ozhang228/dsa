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
binary search for k
**/

class Solution { 
public:
  bool isKValid(vector<int>& piles, int hours, int bananasPerHour) {
    int currCost{};
    for (const int& pile : piles) {
      currCost += pile / bananasPerHour;
      if (pile % bananasPerHour != 0) {
        currCost += 1;
      }

      if (currCost > hours) {
        return false;
      }
    }

    return true;
  }
  int minEatingSpeed(vector<int>& piles, int h) {
    int l{1};
    int r = piles.size() * (*max_element(piles.begin(), piles.end()));

    int minSpeed{INT_MAX};

    while (l <= r) {
      int mid{l + (r - l) / 2};
      if (isKValid(piles, h, mid)) {
        minSpeed = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    return minSpeed;
  }
};
