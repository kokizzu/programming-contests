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

struct ImportantSequence {
  int getCount(vector <int> B, string operators);
};

typedef long long ll;
const ll INF = 1LL << 60;

int ImportantSequence::getCount(vector <int> B, string operators) {
  int N = B.size();

  ll xmi = 1, xma = INF;

  ll a = 0;
  bool b = true;
  rep (i, N) {
    if (operators[i] == '+') {
      b = !b;
      a = B[i] - a;
    } else {
      a = a - B[i];
    }

    if (b) xmi = max(xmi, 1LL - a);
    else   xma = min(xma, a - 1LL);
  }

  if (xma == INF) return -1;
  else return max(0LL, xma - xmi + 1);
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
			int B[]                   = {3, -1, 7};
			string operators          = "+-+";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ImportantSequence().getCount(vector <int>(B, B + (sizeof B / sizeof B[0])), operators);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int B[]                   = {1};
			string operators          = "-";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ImportantSequence().getCount(vector <int>(B, B + (sizeof B / sizeof B[0])), operators);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int B[]                   = {1};
			string operators          = "+";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = ImportantSequence().getCount(vector <int>(B, B + (sizeof B / sizeof B[0])), operators);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int B[]                   = {10};
			string operators          = "+";
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = ImportantSequence().getCount(vector <int>(B, B + (sizeof B / sizeof B[0])), operators);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int B[]                   = {540, 2012, 540, 2012, 540, 2012, 540};
			string operators          = "-+-+-+-";
			int expected__            = 1471;

			clock_t start__           = clock();
			int received__            = ImportantSequence().getCount(vector <int>(B, B + (sizeof B / sizeof B[0])), operators);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int B[]                   = ;
			string operators          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ImportantSequence().getCount(vector <int>(B, B + (sizeof B / sizeof B[0])), operators);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int B[]                   = ;
			string operators          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ImportantSequence().getCount(vector <int>(B, B + (sizeof B / sizeof B[0])), operators);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int B[]                   = ;
			string operators          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ImportantSequence().getCount(vector <int>(B, B + (sizeof B / sizeof B[0])), operators);
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
