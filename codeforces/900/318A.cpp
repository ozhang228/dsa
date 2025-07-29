#include <bits/stdc++.h>
using namespace std;

/**
first n positive int

all odd form 1 to n then all even, find out which at k

Input
The only line of input contains integers n and k (1 ≤ k ≤ n ≤ 1012).

Please, do not use the %lld specifier to read or write 64-bit integers in C++.
It is preferred to use the cin, cout streams or the %I64d specifier.

Output
Print the number that will stand at the position number k after Volodya's
manipulations.

Examples
InputCopy
10 3
OutputCopy
5
InputCopy
7 7
OutputCopy
6
Note
In the first sample Volodya's sequence will look like this: {1, 3, 5, 7, 9, 11,
2, 4, 6, 8, 10,}. The third place in the sequence is therefore occupied by the
number 5.
 **/

// n is odd
// more odd than even, thus we can just ceil it to find out if we are there
// n is even
// k is in evens

long long n, k;
void solve() {
  if (k > ceil(n / 2.0)) {
    long long newK = (k - ceil(n / 2.0));
    printf("%lld", newK * 2);
    return;
  } else {
    printf("%lld", (k * 2) - 1);
    return;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
  solve();
}
