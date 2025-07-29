#include <bits/stdc++.h>
using namespace std;

/**
p levels and q levels

**/

int n, p;
unordered_set<int> levels;
void solve() {}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  cin >> p;
  for (int i = 0; i < p; ++i) {
    int curr;
    cin >> curr;
    levels.insert(curr);
  }

  cin >> p;
  for (int i = 0; i < p; ++i) {
    int curr;
    cin >> curr;
    levels.insert(curr);
  }

  if (levels.size() == n) {
    printf("I become the guy.");
  } else {
    printf("Oh, my keyboard!");
  }
}
