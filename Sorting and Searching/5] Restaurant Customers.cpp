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

// Main Idea = Store the start and end time of a customer as a pair : {start, +1} and {end, -1}, to signify that at each 
// start time a customer enters, and at each end time the customer leaves so the net is zero.
// Then, sort the vector, and store the maximum number of customers in the restaurant at any time by traversing through the vector
// and continuously adding the second element of each pair.

// Time Complexiy = O(n.logn  + n), 'n.logn' to sort the vector and 'n' to traverse through the vector
// Space Complexity = O(n), to store the vector of pairs

int main()
{
    int n;
    cin>>n;
    vector<pair<int, int>> customer;
    for(int i=0; i<n; i++)
    {
        int start, end;
        cin>>start>>end;
        customer.push_back({start, +1});
        customer.push_back({end, -1});
    }
    sort(customer.begin(), customer.end());
    int sum = 0;
    int maxi = -1;
    for(int i=0; i<2*n; i++)
    {   
        sum = sum + customer[i].second;
        if(sum > maxi)
            maxi = sum;
    }
    cout<<maxi<<endl;
    return 0;   
}