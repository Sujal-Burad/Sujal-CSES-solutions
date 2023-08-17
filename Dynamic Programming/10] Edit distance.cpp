#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> // for map operations
#include<unordered_map>
#define mod 1000000007
 
// Main Idea = dp[i][j] = Minimum number of moves to change the first i letters of the string into first j letters of the result.
// dp[i][j] = min(dp[i][j], dp[i-1][j] + 1), if (i != 0). We are adding 1 since here we are deleting the ith character in the 1st string.
// dp[i][j] = min(dp[i][j], dp[i][j-1] + 1), if (j != 0). We are adding 1 since here we are adding the jth character to the 1st string.
// dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (a[i-1] != b[j-1])). The replace operation.

// Time Complexity = O(n)
// Space Complexity = O(n)
int main(){
    fio;
   string a, b;
  cin >> a >> b;
  int na = a.size(), nb = b.size();
  vector<vector<int>> dp(na+1, vector<int>(nb+1,1e9));
  dp[0][0] = 0;
  for (int i = 0; i <= na; i++) {
    for (int j = 0; j <= nb; j++) {
      if (i) {
	dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
      }
      if (j) {
	dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
      }
      if (i && j) {
	dp[i][j] = min(dp[i][j], dp[i-1][j-1]+(a[i-1] != b[j-1]));
      }
    }
  }
  cout << dp[na][nb] << endl;
    return 0;
}