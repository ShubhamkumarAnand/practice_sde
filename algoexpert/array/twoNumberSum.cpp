/*
   👲 :  imskanand
   ⏳ :  Tuesday : (18-Apr-23)
   ⏰ :  (20:56)
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

// My Solution: Brute Force

/**
 * Space Complexity -> O(1)
 * Reason -> Self Explanatory
 * Time Complexity -> O(n^2)
 * Reason -> Self Explanatory
 */

vector<int> twoNumberSum(vector<int>& array, int targetSum) {
  vector<int> res(2);
  for (int i = 0; i < array.size() - 1; i++) {
    for (int j = i + 1; j < array.size(); j++) {
      if (array[i] + array[j] == targetSum) {
        res[0] = array[i];
        res[1] = array[j];
        return res;
      }
    }
  }
  return res;
}

// Solution: This uses sort function
/**
 * Space Complexity -> O(1)
 * Reason -> Self Explanatory
 * Time Complexity -> O(n(log(n))+n) ==> O(n(log(n)))
 * Reason -> Self Explanatory
 */
vector<int> twoNumberSum(vector<int>& array, int targetSum, int n) {
  vector<int> res(2);
  sort(array.begin(), array.end());
  int i = 0, j = n - 1;
  while (i < j) {
    int sum = array[i] + array[j];
    if (sum == targetSum) {
      res[0] = array[i];
      res[1] = array[j];
      return res;
    } else if (sum > targetSum) {
      j--;
    } else {
      i++;
    }
  }
  return res;
}

// Optimal Solution using Hashmap
/**
 * Space Complexity -> O(n)
 * Reason -> We are using the Map
 * Time Complexity -> O(n)
 * Reason -> Traversing the Array Once
 */
vector<int> twoNumberSumOp(vector<int>& array, int targetSum, int n) {
  map<int, bool> mp;
  vector<int> res(2);
  for (int i = 0; i < n; i++) {
    int value = targetSum - array[i];
    if (mp[value]) {
      res[0] = array[i];
      res[1] = value;
      return res;
    } else {
      mp[array[i]] = true;
    }
  }
  debug(mp);
  return res;
}

void solve(int testcase) {
  vector<int> array = {3, 5, -4, 8, 11, 1, -1, 6};
  int targetSum = 14;

  vector<int> res = twoNumberSumOp(array, targetSum, array.size());
  for (int i = 0; i < 2; i++) {
    cout << res[i] << " ";
  }
  cout << "\n";
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
  cerr << "Time taken : " << ((long double)duration.count()) / ((long double)1e9) * 1000000 << " ms " << endl;
  return 0;
}

/**
 * Space Complexity -> O(n)
 * Reason -> Self Explanatory
 * Time Complexity -> O(n)
 * Reason -> Self Explanatory
 */