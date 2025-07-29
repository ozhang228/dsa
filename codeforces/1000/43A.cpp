#include <bits/stdc++.h>
using namespace std;

/**
n lines describes on goal
name of the team that scored it, no ties

first line is num lines in the discription
find the most goals
 **/

vector<string> goals{};

void solve() {
  unordered_map<string, int> scored{};

  string max_scorer{};
  for (const auto &g : goals) {
    scored[g] += 1;
    if (scored[g] > scored[max_scorer]) {
      max_scorer = g;
    }
  }

  printf("%s", max_scorer.c_str());
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int numGoals;
  cin >> numGoals;
  while (numGoals--) {
    string team{};
    cin >> team;
    goals.push_back(team);
  }
  solve();
}
