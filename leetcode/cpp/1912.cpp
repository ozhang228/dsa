
#include <bits/stdc++.h>
#include <queue>
using namespace std;

struct pair_hash {
  inline std::size_t operator()(const std::pair<int, int> &v) const {
    return v.first * 31 + v.second;
  }
};

/**
n shops

three operations
  search
    find cheapest 5 shops that have an unrented copy
  rent
    rent an unrented copy given a movie from a given shop
    only called if its unrented
  drop
    unrent
    only called if it had previously rented out
  return
    returns the 5 cheapest 5 rented movies

a shop has movies with price p and has at most one

lazy deletion?
access a movie using make_pair<shop, movie>

**/

class MovieRentingSystem {
public:
  // shop to movie to shop to <price, rented>
  unordered_map<int, unordered_map<int, pair<int, bool>>> movies;

  // movie to -price, -shopid, -movieId
  unordered_map<int, priority_queue<tuple<int, int, int>>> unrented_movies;

  // -price, -shopid, -movieId
  priority_queue<tuple<int, int, int>> rented;
  MovieRentingSystem(int n, vector<vector<int>> &entries) {
    for (const auto &e : entries) {
      int shop = e[0];
      int movie = e[1];
      int price = e[2];

      movies[shop][movie] = make_pair(price, false);
      printf("%d %d %d\n", shop, movie, price);
      unrented_movies[movie].push(make_tuple(-price, -shop, -movie));
    }
  }

  vector<int> search(int movie) {
    vector<int> ans{};
    vector<tuple<int, int, int>> tempStorage{};
    priority_queue<tuple<int, int, int>> unrented = unrented_movies[movie];
    unordered_set<pair<int, int>, pair_hash> visited{};

    while (unrented.size() > 0 && tempStorage.size() < 5) {
      //   printf("%d\n", unrented.size());
      tuple<int, int, int> curr = unrented.top();
      unrented.pop();

      int price = -get<0>(curr);
      int shopId = -get<1>(curr);
      int movieId = -get<2>(curr);

      if (movies[shopId][movieId].second ||
          visited.find(make_pair(shopId, movieId)) != visited.end()) {
        continue;
      }

      visited.insert(make_pair(shopId, movieId));
      ans.push_back(shopId);
      tempStorage.push_back(curr);
    }

    for (const auto &item : tempStorage) {
      unrented.push(item);
    }

    return ans;
  }

  void rent(int shop, int movie) {
    pair<int, bool> curr = movies[shop][movie];
    movies[shop][movie] = make_pair(curr.first, !curr.second);
    rented.push(make_tuple(-curr.first, -shop, -movie));
  }

  void drop(int shop, int movie) {
    pair<int, bool> curr = movies[shop][movie];
    movies[shop][movie] = make_pair(curr.first, !curr.second);
    unrented_movies[movie].push(make_tuple(-curr.first, -shop, -movie));
  }

  vector<vector<int>> report() {
    vector<vector<int>> ans{};
    vector<tuple<int, int, int>> tempStorage{};
    unordered_set<pair<int, int>, pair_hash> visited{};

    while (rented.size() > 0 && tempStorage.size() < 5) {
      tuple<int, int, int> curr = rented.top();
      rented.pop();

      int price = -get<0>(curr);
      int shopId = -get<1>(curr);
      int movieId = -get<2>(curr);

      if (!movies[shopId][movieId].second ||
          visited.find(make_pair(shopId, movieId)) != visited.end()) {

        continue;
      }

      visited.insert(make_pair(shopId, movieId));
      ans.push_back({shopId, movieId});
      tempStorage.push_back(curr);
    }

    for (const auto &item : tempStorage) {
      rented.push(item);
    }

    return ans;
  }
};
