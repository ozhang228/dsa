#include <bits/stdc++.h>
using namespace std;

/**
Question

- adds horizontally to right end of the row
- either attracted or repelled and forms a group, sole magnet is its own group

Mike arranged multiple magnets in a row. Determine the number of groups that the
magnets formed.
- basically add one everytime it differs

Input
- int magCnt
- 01 or 10 for plus-minus and minus plus for magCount

Output
On the single line of the output print the number of groups of magnets.
**/

void solve(vector<string> mags) {
  int groups = 1;
  char prev = mags[0][1];

  for (int i = 1; i < mags.size(); ++i) {
    if (mags[i][0] == prev) {
      // printf("Success: %d\n", i);
      groups += 1;
    }
    prev = mags[i][1];
  }
  printf("%d", groups);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int magCnt;
  cin >> magCnt;
  vector<string> mags{};

  for (int i = 0; i < magCnt; ++i) {
    string mag{};
    cin >> mag;
    // printf("%s ", mag.c_str());
    mags.push_back(mag);
  }

  solve(mags);
}
