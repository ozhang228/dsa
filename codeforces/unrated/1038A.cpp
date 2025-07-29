#include <bits/stdc++.h>
using namespace std;

/**

 **/

void solve(int n, int m) {
  if (n == 1 || m == 1 || (n <= 2 && m <= 2))
    printf("NO\n");
  else {
    printf("YES\n");
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int numCases;
  cin >> numCases;
  while (numCases--) {
    int n, m;
    cin >> n >> m;
    solve(n, m);
  }
}
