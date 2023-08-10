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

// Main Idea = This can be solved using the concept of multiset and upper_bound. First, store the 'n' prices in a multiset so that
// they are sorted in an ascending order and the duplicates are also taken care of. Then, for each maximum price the customer is 
// willing to pay, get its upper_bound(first element greater than the given price). If the upper_bound is the first element in the
// multiset, print "-1", since no price is less than or equal to the maximum price. Else, print the element just to the left of 
// upper_bound.

// Time complexity = O(n.logn + n), 'n.logn' to insert element in the multiset, and 'n' for the upper_bound
// Space Complexity = O(n), to store the ticket price and the maximum price each customer is willing to pay.

int main()
{
    int n, m;
    cin>>n>>m;
    multiset<int> price;
    int p;
    for(int i=0; i<n; i++)
    {
        cin>>p;
        price.insert(p);
    }
    for(int i=0; i<m; i++)
    {
        cin>>p;
        auto it = price.upper_bound(p);
        if(it == price.begin())
            cout<<"-1"<<endl;
        else
        {
            cout<<*(--it)<<endl;
            price.erase(it);
        }
    }
    return 0;
}