#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)


int main() {
  int T;
  scanf("%d", &T);
  rep (ca, T) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("Case %d: %s\n", ca + 1,
           a <= 20 && b <= 20 && c <= 20 ? "good" : "bad");
  }

  return 0;
}
