#include <bits/stdc++.h>
using namespace std;

/**
Question
sell for k, unlimited shovels
unlimited 10-burle coins and one of r bulles between 1 and 9
buy until no change

first number x what ends in r

Input
The single line of input contains two integers k and r (1 ≤ k ≤ 1000, 1 ≤ r ≤ 9)
— the price of one shovel and the denomination of the coin in Polycarp's pocket
that is different from "10-burle coins".

Remember that he has an unlimited number of coins in the denomination of 10,
that is, Polycarp has enough money to buy any number of shovels.

Output
Print the required minimum number of shovels Polycarp has to buy so that he can
pay for them without any change.

**/

void solve(int k, int r) {
  int coins = 0;

  while (true) {
    coins += k;
    if (coins % 10 == r || coins % 10 == 0) {
      printf("%d", coins / k);
      return;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int k;
  int r;
  cin >> k >> r;

  solve(k, r);
}
