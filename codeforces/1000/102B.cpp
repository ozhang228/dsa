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

void solve() {}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  if (s.size() == 1) {
    cout << 0;
    return 0;
  }

  long long ans = 1;
  long long sum = 0;
  for (char c : s)
    sum += c - '0';

  while (sum >= 10) {
    long long newN = 0;

    while (sum != 0) {
      newN += sum % 10;
      sum /= 10;
    }

    sum = newN;
    ans += 1;
  }

  cout << ans;
  return 0;
}
