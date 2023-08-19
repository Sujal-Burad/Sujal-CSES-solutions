#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> // for map operations
#include<unordered_map>
// #define mod 1000000007
#include <algorithm>
 
// Main Idea =
// The division is possible only if sum of 1...n is even, and print "0" for odd sum.
// dp[i][x] = Number of ways to make sum x using the subset of the numbers 1...i.
// For counting the number of ways to make sum x using the values up to i, we can either consider the ith value or exclude it.
// Hence, dp[i][x] = dp[i-1][x](ith element = excluded) + dp[i-1][x - i](ith element = included)

// Time Complexity = O(n^2)
// Space Complexity = O(n^2), for the dp array 

int main() {
  int mod = 1e9+7;
  int n;
  cin >> n;
  int target = n*(n+1)/2;
  if (target%2) {
    cout << 0 << endl;
    return 0;
  }
  target /= 2;
 
  vector<vector<int>> dp(n,vector<int>(target+1,0));
  dp[0][0] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= target; j++) {
      dp[i][j] = dp[i-1][j];
      int left = j-i;
      if (left >= 0) {
	(dp[i][j] += dp[i-1][left]) %= mod;
      }
    }
  }
  cout << dp[n-1][target] << endl;
}