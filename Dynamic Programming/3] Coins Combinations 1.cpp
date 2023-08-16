#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> // for map operations
#include<unordered_map>

// Main Idea = First sort the array containing the value of coins. Form a dp array initialized with 0.
// dp[w] = number of ways to achieve the sum of values, w.
// For each 'w' we will iterate through the complete array, and if coin[i] <= w, then dp[w] = dp[w] + dp[w-coins[i]].

// Time Complexity = O(n.target), to iterate through the complete array for each w.
// Space Complexity = O(target), for the dp array

int main(){
    int n, target;
    cin>>n>>target;
    vector<int> coins(n);
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        coins[i] = x;
    }
    sort(coins.begin(), coins.end());
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for(int i=1; i<=target; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i-coins[j] >= 0)
            {
                dp[i] = (dp[i] + dp[i-coins[j]]) % 1000000007 ;
            }
        }
    }
    if(dp[target] == 1e9)
        cout<<-1<<endl;
    else
        cout<<dp[target]<<endl;
    return 0;
}