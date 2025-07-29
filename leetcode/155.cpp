#include <bits/stdc++.h>
using namespace std;

/**

push, pop, top, get min in O(1)

have a stack to do the first few

keep a secondary stack that you only push to if its empty or if the number is <=
that one

**/
class MinStack {
public:
  stack<int> stk{};
  stack<int> min{};

  MinStack() {}

  void push(int val) {
    stk.push(val);
    if (min.empty() || min.top() >= val) {
      min.push(val);
    }
  }

  void pop() {
    int top = stk.top();
    stk.pop();

    if (min.top() == top) {
      min.pop();
    }
  }

  int top() { return stk.top(); }

  int getMin() { return min.top(); }
};
