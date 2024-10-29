#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll n, m;
vl par;

ll GetRoot(ll x) {
  if (par[x] == x) return x;

  return par[x] = GetRoot(par[x]);
}

void Join(ll x, ll y) {
  x = GetRoot(x);
  y = GetRoot(y);

  if (x == y) return;

  if (x < y) {
    par[y] = x;
  } else {
    par[x] = y;
  }
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n >> m;
  par = vl(n + 1, 0);
  for (auto i = 1; i <= n; ++i) {
    par[i] = i;
  }

  for (auto a = 1; a <= n; ++a) {
    for (auto b = 1; b <= n; ++b) {
      ll is_connected;
      cin >> is_connected;
      if (is_connected == 1) {
        const auto& pa = GetRoot(a);
        const auto& pb = GetRoot(b);

        if (pa == pb) continue;

        Join(a, b);
      }
    }
  }

  ll prev = -1;
  for (auto i = 0; i < m; ++i) {
    ll dest;
    cin >> dest;
    if (prev > 0) {
      const auto& pa = GetRoot(prev);
      const auto& pb = GetRoot(dest);

      if (pa != pb) {
        cout << "NO";
        return 0;
      }
    }
    prev = dest;
  }

  cout << "YES";

  return 0;
}