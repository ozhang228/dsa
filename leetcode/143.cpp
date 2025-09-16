#include <bits/stdc++.h>
using namespace std;

struct pair_hash {
  inline std::size_t operator()(const std::pair<int, int> &v) const {
    return v.first * 31 + v.second;
  }
};

void printvi(vector<int> v) {
  printf("[");

  for (int i = 0; i < v.size(); ++i) {
    printf("%d", v[i]);

    if (i != v.size() - 1) {
      printf(",");
    }
  }
  printf("]");
}

/**

**/

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  void reorderList(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *midPoint = slow;

    ListNode *prev = nullptr;
    ListNode *curr = slow;
    ListNode *next = nullptr;

    while (curr != nullptr) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }

    ListNode *forwardPtr = head;
    ListNode *backPtr = prev;

    while (backPtr != midPoint) {
      ListNode *nextFromBack = backPtr->next;
      ListNode *nextFromFront = forwardPtr->next;

      forwardPtr->next = backPtr;
      backPtr->next = nextFromFront;
      forwardPtr = nextFromFront;
      backPtr = nextFromBack;
    }
  }
};
