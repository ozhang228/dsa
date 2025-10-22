#include <bits/stdc++.h>
using namespace std;

/**

**/

class LRUCache {
public:
  unordered_map<int, list<pair<int, int>>::iterator> key_to_item;
  list<pair<int, int>> items;
  int capacity;

  LRUCache(int capacity) : capacity(capacity) {}
  int get(int key) {
    auto itemIter{key_to_item.find(key)};
    if (itemIter == key_to_item.end()) {
      return -1;
    }
    items.splice(items.begin(), items, itemIter->second);
    return itemIter->second->second;
  }
  void put(int key, int value) {
    unordered_map<int, list<pair<int, int>>::iterator>::iterator itemIter{
        key_to_item.find(key)};

    if (itemIter != key_to_item.end()) {
      itemIter->second->second = value;
      items.splice(items.begin(), items, itemIter->second);
    } else {
      if (items.size() == capacity) {
        auto oldPair = items.back();
        items.pop_back();
        key_to_item.erase(oldPair.first);
      }

      items.emplace_front(key, value);
      key_to_item[key] = items.begin();
    }
  }
};
