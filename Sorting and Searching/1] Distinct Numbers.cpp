#include<bits/stdc++.h>
#define ll  long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> // for map operations
#include<unordered_map>
// #define mod 1000000007
#include <algorithm>

// Main Idea = We can simply use a set to store the number of distinct values

// Time Complexity = O(N.log(N)), time taken to insert all the elements into the set
// Space Complexity = O(N), at max all the elements would be different, and we would have to store all of them

// A simple unordered frequency map can also be used to further reduce the time complexity.

int main()
{
    int n;
    cin>>n;
    int arr[n];
    set<int> st;
    int count = 0;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        if(st.find(arr[i]) == st.end())
        {
            st.insert(arr[i]);
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}