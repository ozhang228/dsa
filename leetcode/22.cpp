#include <bits/stdc++.h>
using namespace std;

struct pair_hash {
  inline std::size_t operator()(const std::pair<int, int> &v) const {
    return v.first * 31 + v.second;
  }
};

/**
generate all combinations of well-formed parenthesis

backtracking?

end condition
  pairs == n

if we are less than 2 * n
  call with add a left paren
  remove

if we have more left than right
  call with add right
  remove
**/

string stackToString(stack<char> stack) {
  string s = "";
  while (!stack.empty()) {
    s += stack.top();
    stack.pop();
  }
  reverse(s.begin(), s.end());
  return s;
}

class Solution {
public:
  vector<string> ans{};
  int n;
  vector<string> generateParenthesis(int n) {
    this->n = n;
    stack<char> curr{};
    this->backtrack(curr, 0, 0);
    return this->ans;
  }

  void backtrack(stack<char> curr, int l, int r) {
    if (l == r == this->n) {
      ans.push_back(stackToString(curr));
      return;
    }

    if (l + r >= 2 * this->n) {
      return;
    }

    curr.push('(');
    this->backtrack(curr, l + 1, r);
    curr.pop();

    if (l > r) {
      curr.push(')');
      this->backtrack(curr, l, r + 1);
      curr.pop();
    }
  }
};
