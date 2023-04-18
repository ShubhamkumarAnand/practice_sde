/*
   👲 :  imskanand
   ⏳ :  Tuesday : (18-Apr-23)
   ⏰ :  (15:14)
*/

// Pragmas
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

// header files
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>  // for pbds
#include <ext/pb_ds/tree_policy.hpp>

// namespace
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

// algo-debug
#ifdef DEBUG
#include "algo/debug.h"
#else
#define debug(...)
#endif

// Constants
#define PI 3.1415926535
#define INF 4e18
#define EPS 1e-9
#define MOD 1000000007

// Aliases
using ll = long long int;
using ull = unsigned long long int;
using ld = long double;

// macros
#define int long long
#define all(s) s.begin(), s.end()
#define pb push_back
#define eb emplace_back
#define ppc __builtin_popcount
#define parity(x) __builtin_parity(x)  // gives true for odd and false for even
#define ppcll __builtin_popcountll
#define msb(x) 63 - __builtin_clzll(x)  // gives the most significant bit of the number
#define sz(x) (int)x.size()
#define F first
#define acc accumulate
#define S second
#define getunique(v)                              \
  {                                               \
    sort(v.begin(), v.end());                     \
    v.erase(unique(v.begin(), v.end()), v.end()); \
  }

// Trust On Yourself and Start Doing!

// Memory Efficient Solution
bool isValidSubsequence(vector<int>& array, vector<int>& subsequence) {
  int seqIdx = 0;
  for (int i = 0; i < array.size(); i++) {
    if (seqIdx < subsequence.size()) {
      if (array[i] == subsequence[seqIdx])
        seqIdx++;
    }
  }
  return seqIdx == subsequence.size();
}

// Time Efficient Solution
bool isValidSubsequence(vector<int>& array, vector<int>& subsequence, int arrIdx, int seqIdx) {
  if (seqIdx == 0) {
    return true;
  }
  if (arrIdx == 0) {
    return false;
  }

  if (subsequence[seqIdx - 1] == array[arrIdx - 1]) {
    return isValidSubsequence(array, subsequence, arrIdx - 1, seqIdx - 1);
  }

  return isValidSubsequence(array, subsequence, arrIdx - 1, seqIdx);
}

void solve(int testcase) {
  vector<int> array = {5, 1, 22, 25, 6, -1, 8, 10};
  vector<int> subsequence = {1, 6, -1, 12};

  if (isValidSubsequence(array, subsequence, array.size(), subsequence.size())) {
    cout << "YES"
         << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(25);
  cerr << fixed << setprecision(10);
  auto start = std::chrono::high_resolution_clock::now();
  int n = 1;
  // cin >> n;
  for (int i = 1; i <= n; i++) {
    solve(i);
  }
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
  cerr << "Time taken : " << ((long double)duration.count()) / ((long double)1e9) << "s " << endl;
  return 0;
}

/**
 * Space Complexity -> O(1)
 * Reason -> Self Explanatory
 * Time Complexity -> O(n)
 * Reason -> Self Explanatory
 */