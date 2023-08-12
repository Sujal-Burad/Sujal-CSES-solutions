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
 
// Main Idea = This can be solved using the concept of 'multiset' and 'upper_bound'. Whenever the 'upper_bound' of an element is not 
// present in the multiset, we will have to insert this element into the multiset. And, when the 'upper_bound' of an element is present
// in the multiset, we could simply erase the 'upper_bound' value and insert the current value in the multiset.
// We are using multiset because, there can be instances when the sizes of two cubes is same, and we will have to insert both of them
// into the multiset.
// Multiset stores the values entered in ascending order, even if duplicates are present, unlike set where the duplicates are removed.

// Time Complexity = O(n.logn), taking into effect 'upper_bound' and 'insert' for set.
// Space Complexity = O(n), to store the n elements in set

int main()
{
    int n; cin>>n;
    multiset<int> ans;
    for(int i=0; i<n; i++)
    {
        int val; cin>>val;
        auto it = ans.upper_bound(val);
        if(it == ans.end())
        {
            ans.insert(val);
        }
        else
        {
            ans.erase(it);
            ans.insert(val);
        }
    }
    cout<<ans.size()<<endl;
    return 0;
}