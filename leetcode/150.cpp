#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

struct pair_hash {
  inline std::size_t operator()(const std::pair<int, int> &v) const {
    return v.first * 31 + v.second;
  }
};

/**

**/

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> intermediate{};

    for (const auto &token : tokens) {
      if (token == "+") {
        int num1 = intermediate.top();
        intermediate.pop();
        int num2 = intermediate.top();
        intermediate.pop();
        intermediate.push(num1 + num2);
      } else if (token == "-") {
        int num1 = intermediate.top();
        intermediate.pop();
        int num2 = intermediate.top();
        intermediate.pop();
        intermediate.push(num2 - num1);
      } else if (token == "*") {
        int num1 = intermediate.top();
        intermediate.pop();
        int num2 = intermediate.top();
        intermediate.pop();
        intermediate.push(num1 * num2);
      } else if (token == "/") {
        int num1 = intermediate.top();
        intermediate.pop();
        int num2 = intermediate.top();
        intermediate.pop();
        intermediate.push(num2 / num1);
      } else {
        intermediate.push(stoi(token));
      }
    }

    return intermediate.top();
  }
};

int main() {
  Solution s{};
  vector<string> tokens{"4", "13", "5", "/", "+"};
  printf("%d", s.evalRPN(tokens));

  return 0;
}
