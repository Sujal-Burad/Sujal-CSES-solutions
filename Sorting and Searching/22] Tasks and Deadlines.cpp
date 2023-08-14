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
 
// Main Idea = Sort the pair in non-decreasing order. Then, each time get the difference between the second value with the summation
// of first value.

// Time Complexity = O(n.logn), sorting the array
// Space Complexity = O(1), to store the total reward.

int main()
{
    int n; cin>>n;
    vector<pair<int, int>> vec(n);
    for(int i=0; i<n; i++)
    {
        cin>>vec[i].first>>vec[i].second;
    }
    sort(vec.begin(), vec.end());
    ll reward = 0;
    ll daysover = 0;
    for(int i=0; i<n; i++)
    {
        daysover = daysover + vec[i].first;
        reward = reward + vec[i].second - daysover;
        // cout<<reward<<endl;
    }
    cout<<reward<<endl;
    return 0;
}