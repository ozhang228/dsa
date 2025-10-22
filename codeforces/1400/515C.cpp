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

  int n;
  cin >> n;

  // ignore all 1s or zero
  // 2 -> 2
  // 3 -> 3
  // 4 -> 2, 2, 3
  // 5 -> 5
  // 6 -> 3, 5
  // 7 -> 7
  // 8 -> 2, 2, 2, 7
  // 9 -> 3, 3, 2, 7
  string a;
  cin >> a;

  unordered_map<int, int> chars{};

  for (int i = 0; i < a.size(); ++i) {
    switch (a[i]) {
    case '0':
      break;
    case '1':
      break;
    case '2':
      chars[2] += 1;
      break;
    case '3':
      chars[3] += 1;
      break;
    case '4':
      chars[2] += 2;
      chars[3] += 1;
      break;
    case '5':
      chars[5] += 1;
      break;
    case '6':
      chars[3] += 1;
      chars[5] += 1;
      break;
    case '7':
      chars[7] += 1;
      break;
    case '8':
      chars[2] += 3;
      chars[7] += 1;
      break;
    case '9':
      chars[2] += 1;
      chars[3] += 2;
      chars[7] += 1;
      break;
    }
  }

  string ans{};

  for (int i = 9; i > 1; --i) {
    for (int j = 0; j < chars[i]; ++j) {
      ans += to_string(i);
    }
  }

  cout << ans;
}
