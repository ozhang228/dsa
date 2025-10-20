#include <bits/stdc++.h>
using namespace std;

struct pair_hash {
  inline std::size_t operator()(const std::pair<int, int> &v) const {
    return v.first * 31 + v.second;
  }
};

template <class T> void print_v(vector<T> &v) {
  if (v.size() == 0) {
    cout << "{}\n";
    return;
  }
  cout << "{";
  for (auto x : v)
    cout << x << ",";
  cout << "\b}\n";
}

void solve(vector<int> heights) {
  // when energy is about to go negative add that to cost and revert to do
  int cost{};
  int curEnergy{};

  for (int i = 0; i < heights.size() - 1; ++i) {
    curEnergy += heights[i] - heights[i + 1];

    if (curEnergy < 0) {
      cost += abs(curEnergy);
      curEnergy = 0;
    }
  }

  cout << cost;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> heights(n + 1);
  heights[0] = 0;

  for (int i = 1; i < n + 1; ++i) {
    cin >> heights[i];
  }

  solve(heights);
}
