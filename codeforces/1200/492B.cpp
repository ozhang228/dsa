#include <bits/stdc++.h>
#include <cstdio>
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

void solve(vector<int> lanterns, int streetLen) {
  lanterns.push_back(0);
  sort(lanterns.begin(), lanterns.end());

  double minD = 0;
  double prevRadius = 0;

  for (size_t i = 1; i < lanterns.size() - 1; ++i) {
    double lCost = lanterns[i] - (lanterns[i - 1] + prevRadius);

    if (lCost < 0) {
      lCost = 0;
    }

    double rCost = (lanterns[i + 1] - lanterns[i]) / 2.0l;

    // printf("%d %lf %lf\n", lanterns[i], lCost, rCost);

    minD = max(minD, max(lCost, rCost));
    prevRadius = max(rCost, lCost);
  }

  double lCost = lanterns[lanterns.size() - 1] -
                 (lanterns[lanterns.size() - 2] + prevRadius);
  if (lCost < 0) {
    lCost = 0;
  }
  double rCost = streetLen - lanterns[lanterns.size() - 1];
  minD = max(minD, max(lCost, rCost));

  printf("%lf", minD);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int numLanterns;
  cin >> numLanterns;
  int streetLen;
  cin >> streetLen;

  vector<int> lanterns{};

  for (size_t i = 0; i < numLanterns; ++i) {
    int currLantern;
    cin >> currLantern;
    lanterns.push_back(currLantern);
  }
  solve(lanterns, streetLen);
}
