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

// Main Idea = This problem can be solved using the concept of sliding window. Whenever we encounter a new element, we increase the 
// window size from right. And, whenever an element has already been visited, we keep on decreasing the windows size from left, till the current
// element becomes unique in the window.
// Storing of unique elements can be done with the help of sets, and to see if the current element has already been visited or not
// we can use the count function.

// Time complpexity = O(n.logn), because at max we will have to insert n elements and call 'count' for each of them
// Space Complexity = O(n), since we are using set to store the n elements

int main()
{
    int n; cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];
    set<int> st;
    int i=0; int j = 0;
    int ans = 0;
    while(i<=j && j<n)
    {
        while(j<n && !st.count(v[j]))
        {
            st.insert(v[j]);
            ans = max(ans, j-i+1);
            j++;
        }
        while(j<n && st.count(v[j]))
        {
            st.erase(v[i]);
            i++;
        }
    }
    cout<<ans<<endl;
    return 0;
}