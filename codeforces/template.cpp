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

template <class T> void print_p(pair<T, T> &v) {
  cout << "{" << v.f << "," << v.s << "}\n";
}

void solve() {}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int numCases;
  cin >> numCases;
  while (numCases--)
    solve();
}
