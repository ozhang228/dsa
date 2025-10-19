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

void solve(int maxBoxes, vector<pair<int, int>> &containers) {
  sort(containers.begin(), containers.end(),
       [](pair<int, int> a, pair<int, int> b) { return b.second < a.second; });

  int boxesRemaining = maxBoxes;
  int ans{};
  for (int i = 0; i < containers.size(); ++i) {
    if (boxesRemaining == 0)
      break;

    int numToTake = min(boxesRemaining, containers[i].first);
    ans += numToTake * containers[i].second;

    boxesRemaining -= numToTake;
  }

  cout << ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> containers(m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    containers.push_back(make_pair(a, b));
  }

  solve(n, containers);
}
