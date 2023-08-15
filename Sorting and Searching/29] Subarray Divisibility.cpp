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

// Main Idea = This can be solved using the concept of prefix sum, maps and modulo. It is similar to the 'Subarrays Sum 2' problem.

// Time Complexity = O(n).
// Space Complexity = O(n), to store the prefix sums in map.

int main()
{
    int n; cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++)
        cin>>vec[i];
 
    unordered_map<ll, ll> mpp;
    mpp[0] = 1;
    ll count = 0;
    ll premod = 0;
    for(int i=0; i<n; i++)
    {
        int mod = vec[i]%n;
        premod = (premod + mod + n)%n;
        count = count + mpp[premod];
        mpp[premod]++;
    }
    cout<<count<<endl;
    return 0;
}