#include<bits/stdc++.h>
#define ll  long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> // for map operations
#include<unordered_map>
// #define mod 1000000007
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

// Main Idea = To find the minimum time, all the machines should be run simultaneously. We can also observe that if a machine produces
// x products in time t1, then it must produce at least x products in time t2 > t1.
// We will apply the concept of binary search. Initially, let 'high' = 1e18(a very large number), and 'low' = 0. Then for each 'mid' that we
// find, find the total number of products that are created within mid time.
// If the total number of products created >= t, update the final answer to 'mid' and 'high' to mid - 1.
// Else if the total number of products created < t, update 'low' to mid + 1.
// Finally, after continous iteration of the binary search, we will get the final answer.

// Time Complexity = O(n.log(t)), where t = the largest time we need to consider.
// Space Complexity = O(1), to store the final answer.

int main()
{
    int n; cin>>n;
    int t; cin>>t;
    vector<int> vec;
    for(int i=1; i<=n; i++)
    {
        int val; cin>>val;
        vec.push_back(val);
    }
    sort(vec.begin(), vec.end());
    ll lo = 0;
    ll hi = 1e18;
    ll ans; 
    while(lo <= hi)
    {
        ll mid= (lo + hi)/2; 
        ll sum = 0;
        for(int i=0; i<n; i++)
        {
            sum = sum + mid/vec[i];
            if(sum >= t)
                break;
        }
        if(sum >= t)
        {
            ans = mid;
            hi = mid-1;
        }
        else
        {
            lo = mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}