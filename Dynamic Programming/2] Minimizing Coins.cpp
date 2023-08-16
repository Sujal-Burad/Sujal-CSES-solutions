#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> // for map operations
#include<unordered_map>

// Main Idea = We can initialize a dp array to find the answer. The element dp[w] represents the minimum number of coins needed to achive
// w. For some w, we can try using every coin. dp[w] can be achieved by transitioning from the state dp[w-coins[i]] and hence adding 
// 1 in the process to dp[w]. Thus, dp[w] = min(dp[w], dp[w-coins[i]] + 1). 
// The dp array should be initialized with very large number like 10^9 but not INT_MAX since it might lead to overflow error.
// At the end if dp[target] = 10^9 print "-1", else print the value of dp[target].

// Time Complexity = O(n.target), since for every w we are iterating through every coin.
// Space Complexity = O(target), to store the dp array.

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
    vector<int> dp(target + 1, 1e9);
    dp[0] = 0;
    for(int i=1; i<=target; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i-coins[j] >= 0)
                dp[i] = min(dp[i], dp[i-coins[j]] + 1);
        }
    }
    if(dp[target] == 1e9)
        cout<<-1<<endl;
    else
        cout<<dp[target]<<endl;
    return 0;
}