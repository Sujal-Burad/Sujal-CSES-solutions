#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> // for map operations
#include<unordered_map>

// Main concept = It involves basics of dynamic programming. A sum 'n' can be constructed by summing the 
// the following possibilites : first getting 'n-1' and then throwing 1, getting 'n-2' and then throwing 2, ..., and getting 'n-6'  
// and then throwing 6.
// We can use dp from 1 to n to get the answer.

// Time Complexity = O(N), to traverse till n.
// Space Complexity = O(N), to store the dp array.

int main(){
    int n;
    cin>>n; 
    long long dp[n+1+6];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;
    for(int i = 7; i<n+7; i++)
    {
        dp[i] = (dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4]+dp[i-5]+dp[i-6]) % 1000000007;
    }
    cout<<dp[n]<<endl;
    return 0;
}