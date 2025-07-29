#include <bits/stdc++.h>
using namespace std;

/**
number of n length and divisible by t
can just do t * pow(10, n)

**/

int n, t;
void solve() {
  if (n == 1 && t == 10) {
    printf("%d", -1);
    return;
  }

  string ans = to_string(t);

  while (ans.size() != n) {
    ans.push_back('0');
  }

  printf("%s", ans.c_str());
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> t;

  solve();
}
