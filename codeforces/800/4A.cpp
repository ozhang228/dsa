#include <bits/stdc++.h>
using namespace std;

// Pete and Billy are great fans of even numbers, that's why they want to divide
// the watermelon in such a way that each of the two parts weighs even number of
// kilos, at the same time it is not obligatory that the parts are equal. The
// boys are extremely tired and want to start their meal as soon as possible,
// that's why you should help them and find out, if they can divide the
// watermelon in the way they want. For sure, each of them should get a part of
// positive weight.
//
// Input
// The first (and the only) input line contains integer number w (1 ≤ w ≤ 100) —
// the weight of the watermelon bought by the boys.
//
// Output
// Print YES, if the boys can divide the watermelon into two parts, each of them
// weighing even number of kilos; and NO in the opposite case.
//
// Examples
// InputCopy
// 8
// OutputCopy
// YES
// Note
// For example, the boys can divide the watermelon into two parts of 2 and 6
// kilos respectively (another variant — two parts of 4 and 4 kilos).

void solve(int w) {
  if (w % 2 == 0 && w != 2) {
    printf("%s", "YES");
  } else {
    printf("%s", "NO");
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int w{};
  cin >> w;
  solve(w);
}
