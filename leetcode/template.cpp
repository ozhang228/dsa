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

**/
