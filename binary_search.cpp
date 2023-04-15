/*
   👲 :  imskanand
   ⏳ :  Saturday : (15-Apr-23)
   ⏰ :  (16:43)
*/

#include "snippet.h"
// Trust On Yourself and Start Doing!

int binarySearch(vector<int>& v, int key, int n) {
  int low = 0;
  int high = n - 1;
  do {
    int mid = ceil((low + high) / 2);
    if (v[mid] == key) {
      return mid;
    } else if (v[mid] > key) {
      high = mid;
    } else {
      low = mid + 1;
    }
  } while (low <= high);
  return -1;
}

void solve(int testcase) {
  // kickstart(testcase);
  // debug(testcase);
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }
  int key;
  cin >> key;
  int index = binarySearch(v, key, n);
  cout << index << endl;
}

int32_t main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

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
  auto duration =
      std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
  // cerr << "Time taken : " << ((long double)duration.count())/((long double)
  // 1e9) <<"s "<< endl;
  return 0;
}

/**
 * Space Complexity -> O(n): O(1)
 * Time Complexity -> O(n): O(log(n))
 */