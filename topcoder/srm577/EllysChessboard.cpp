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
#include <climits>
#include <numeric>
using namespace std;

#define all(c) (c).begin(), (c).end()
#define iter(c) __typeof((c).begin())
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb push_back
#define mp make_pair

struct EllysChessboard {
  int minCost(vector <string> board);
};

int W, H;
bool B[30][30];
int dp[30][30][30][30];

inline int cost(int px, int py, int pw, int ph,
                int x, int y, int w, int h) {
  int c = 0;
  rep (dx, pw) rep (dy, ph) {
    int tx = px + dx;
    int ty = py + dy;
    if (!B[ty][tx]) continue;
    c += max(max(abs(x - px), abs((x + w - 1) - px)),
             max(abs(y - py), abs((y + h - 1) - py)));
  }
  return c;
}

int EllysChessboard::minCost(vector <string> board) {
  int M = board.size();
  int N = board[0].length();
  memset(B, 0, sizeof(B));
  rep (i, M) rep (j, N) {
    if (board[i][j] == '.') continue;
    int x = i + j;  // [0, M+N)
    int y = i + (N - j);  // [0, M+N)
    B[y][x] = true;
  }

  W = H = N + M;
  memset(dp, 0, sizeof(dp));

  for (int w = 1; w <= W; ++w) {
    for (int h = 1; h <= H; ++h) {
      for (int x = 0; x + w <= W; ++x) {
        for (int y = 0; y + h <= H; ++y) {
          int t;
          if (w == 1 && h == 1) {
            t = 0;
          } else {
            t = INT_MAX;
            if (w >= 2) {
              t = min(t, dp[y][x + 1][w - 1][h] + cost(x        , y, 1, h, x, y, w, h));
              t = min(t, dp[y][x    ][w - 1][h] + cost(x + w - 1, y, 1, h, x, y, w, h));
            }
            if (h >= 2) {
              t = min(t, dp[y + 1][x][w][h - 1] + cost(x, y        , w, 1, x, y, w, h));
              t = min(t, dp[y    ][x][w][h - 1] + cost(x, y + h - 1, w, 1, x, y, w, h));
            }
          }
          dp[y][x][w][h] = t;
        }
      }
    }
  }
  return dp[0][0][W][H];
}











// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}

		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}

		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}

	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) {
		cerr << "Example " << casenum << "... ";

		string verdict;
		vector<string> info;
		char buf[100];

		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}

		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}

		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;

		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl;
			cerr << "    Received: " << received << endl;
		}

		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			string board[]            = {"........",
 "........",
 "...#....",
 ".#......",
 ".......#",
 "........",
 "........",
 "........"};
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = EllysChessboard().minCost(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {"........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........",
 "........"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = EllysChessboard().minCost(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {".#......",
 "........",
 "..#..#.#",
 "...#..#.",
 "........",
 "...#...#",
 "...#...#",
 "........"};
			int expected__            = 58;

			clock_t start__           = clock();
			int received__            = EllysChessboard().minCost(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {"##..####",
 "#####..#",
 "..#.#...",
 "#..##.##",
 ".#.###.#",
 "####.###",
 "#.#...#.",
 "##....#."};
			int expected__            = 275;

			clock_t start__           = clock();
			int received__            = EllysChessboard().minCost(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {"########",
 "########",
 "########",
 "########",
 "########",
 "########",
 "########",
 "########"};
			int expected__            = 476;

			clock_t start__           = clock();
			int received__            = EllysChessboard().minCost(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysChessboard().minCost(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysChessboard().minCost(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysChessboard().minCost(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}


int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
