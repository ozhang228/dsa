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

bool isAnagram(string s1, string s2) {
  unordered_map<char, int> s1Cnt{};
  unordered_map<char, int> s2Cnt{};

  for (const char &c : s1) {
    s1Cnt[c] = s1Cnt[c] + 1;
  }

  for (const char &c : s2) {
    s2Cnt[c] = s2Cnt[c] + 1;
  }

  return s1Cnt == s2Cnt;
}

class Solution {
public:
  vector<string> removeAnagrams(vector<string> &words) {
    unordered_set<int> toRemove{};
    vector<string> res{};

    int l = 0;
    int r = 1;

    while (r < words.size()) {
      if (isAnagram(words[l], words[r])) {
        toRemove.insert(r);
        r++;
      } else {
        l = r;
        r++;
      }
    }

    for (int i = 0; i < words.size(); ++i) {
      if (toRemove.find(i) != toRemove.end()) {
        continue;
      }
      res.push_back(words[i]);
    }

    return res;
  }
};
