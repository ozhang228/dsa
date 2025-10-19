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

int solve(const vector<int> &cities, int startingIdx) {
  int caught{cities[startingIdx]};
  int l = startingIdx - 1;
  int r = startingIdx + 1;

  while (l >= 0 && r < cities.size()) {
    if (cities[l] == 1 && cities[r] == 1) {
      caught += 2;
    }
    l--;
    r++;
  }

  while (l >= 0) {
    if (cities[l] == 1) {
      caught++;
    }
    l--;
  }

  while (r < cities.size()) {
    if (cities[r] == 1) {
      caught++;
    }
    r++;
  }

  return caught;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, a;
  cin >> n >> a;

  vector<int> cities(n);

  for (int i = 0; i < n; ++i) {
    cin >> cities[i];
  }

  cout << solve(cities, a - 1);
}
