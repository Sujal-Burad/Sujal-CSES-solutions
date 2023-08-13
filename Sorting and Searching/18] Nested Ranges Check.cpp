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

// Main Idea = First, we will have to sort the ranges. While sorting the ranges, the range with smaller initial starting point should
// come first, and if the initial starting points of the two ranges are same, the one with larger ending point should come first.

// We will first see for the 2nd output, i.e print 1 if a range is contained in some other range, else print 0.
// For each of the range, if its ending point is smaller than or equal to maximum ending point seen so far, then print 1 for it.
// If the ending point for a range is greater than the ending point seen so far, then update the maximum end point and print 0 for the range.
// While starting we can consider the maximum end point seen so far as zero.

// Now, for the 1st output, i.e print 1 if the range contains some other range, else print 0.
// For this we can start from the end. If the ending point of a range is greater than or equal to the maximum end point seen so far,
// then this current range contains some other range, and hence print 1 for this current range.
// If the ending point of current range is less than the maximum end point seen so far, then update the maximum end point seen so far
// with this current range ending point, and print 0 for this current range.

// Time Complexity = O(n.logn), for sorting and traversing through the vector
// Space Complexity = O(n), for storing the answers and vector

bool cmp(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b)
{
    if(a.second.first != b.second.first)
        return a.second.first < b.second.first;
    
    return a.second.second > b.second.second;
}
int main()
{
    int n; cin>>n;
    vector<pair<int, pair<int, int>>> vec(n);
    for(int i=0; i<n; i++)
    {
        cin>>vec[i].second.first;
        cin>>vec[i].second.second;
        vec[i].first = i;
    }
    sort(vec.begin(), vec.end(), cmp);
    vector<pair<int, int>> ans1;
    int end = 0;
    for(int i=0; i<n; i++)
    {
        if(vec[i].second.second <= end)
        {
            ans1.push_back({vec[i].first, 1});
        }
        else
        {
            ans1.push_back({vec[i].first, 0});
            end = vec[i].second.second;
        }
    }
    vector<pair<int, int>> ans2;
    end = 1e9 + 7;
    for(int i=n-1; i>=0; i--)
    {
        if(vec[i].second.second >= end)
            ans2.push_back({vec[i].first, 1});
        else
        {
            ans2.push_back({vec[i].first, 0});
            end = vec[i].second.second;
        }
    }
    sort(ans1.begin(), ans1.end());
    sort(ans2.begin(), ans2.end());
    for(int i=0;i<n;i++)
    {
        cout<<ans2[i].second<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<ans1[i].second<<" ";
    }
    cout<<endl;
    return 0;
}