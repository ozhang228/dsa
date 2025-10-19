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

void solve(const vector<int> &secs) {
  vector<int> increasing(secs.size());
  increasing[0] = 1;

  for (int i = 1; i < secs.size(); ++i) {
    if (secs[i] >= secs[i - 1]) {
      increasing[i] = increasing[i - 1] + 1;
    } else {
      increasing[i] = 1;
    }
  }

  int maxSecs{increasing[secs.size() - 1]};
  int prev{0};

  for (int i = secs.size() - 2; i >= 0; --i) {
    if (secs[i] >= secs[i + 1]) {
      maxSecs = max(maxSecs, increasing[i] + prev + 1);
      prev += 1;
    } else {
      maxSecs = max(maxSecs, increasing[i]);
      prev = 0;
    }
  }

  printf("%d", maxSecs);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<int> secs{};

  for (size_t i = 0; i < n; ++i) {
    int sec;
    cin >> sec;
    secs.push_back(sec);
  }

  solve(secs);
  // int numCases;
  // cin >> numCases;
  // while (numCases--)
  //   solve();
}
