#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pli pair<long long, int>
#define vi vector<int>
#define vll vector<long long>
#define vvii vector<vector<int>> a
#define vvll vector<vector<long long>>
#define vb vector<bool>
#define vs vector<string>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

#define FOR(i, s, e) for (long long int i = s; i < e; i++)
#define FORN(i, n) for (long long int i = 0; i < n; i++)
#define ROF(i, e, s) for (long long int i = e - 1; i >= s; i--)
#define sz(x) (int)(x).size()
#define all(a) (a).begin(), (a).end()
#define each(i, a) for (auto i : a)
#define pb push_back
#define eb emplace_back
#define f first
#define s second
template <class T> void print_v(vector<T> &v) {
  if (v.size() == 0) {
    cout << "{}\n";
    return;
  }
  cout << "{";
  for (auto x : v)
    cout << x << ",";
  cout << "\b}\n";
}

template <class T> void print_p(pair<T, T> &v) {
  cout << "{" << v.f << "," << v.s << "}\n";
}

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll mod = 998244353;
void yes() { cout << "YES\n"; }
void no() { cout << "NO\n"; }
bool prime(ll a) {
  if (a == 1)
    return 0;
  for (int i = 2; i <= round(sqrt(a)); ++i)
    if (a % i == 0)
      return 0;
  return 1;
}
ll pow(ll b, ll exp, ll md) {
  ll ans = 1;
  ll x = b;
  while (exp > 0) {
    if (exp % 2 == 1)
      ans = (ans * x) % md;
    exp /= 2;
    x = (x * x) % md;
  }
  return ans;
}
ll inv(ll b, ll p) { return pow(b, p - 2, p); }
/**

 **/

void solve() {}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int numCases;
  cin >> numCases;
  while (numCases--)
    solve();
}
