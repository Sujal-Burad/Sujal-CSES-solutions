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
 
// Main Idea = The two cases possible are:
// 1] Sum of reading time for all the books except the book taking the largest time is <= time taken to read the lengthiest book, then 
// print max value * 2.
// 2] Sum of reading time for all the books except the book taking the largest time > time to read the lengthiest book, then print the
// sum of reading time of all the books.

// Time Complexity = O(n), to find the sum and the largest value
// Space Complexity = O(1), to store the final answer.

int main()
{
    int n; cin>>n;
    vector<int> vec(n);
    ll sum = 0;
    for(int i=0; i<n; i++)
    {
        cin>>vec[i];
        sum = sum + vec[i];
    }    
    sort(vec.begin(), vec.end());
    sum = sum - vec[n-1];
    if(sum <= vec[n-1])
        cout<<vec[n-1]*2<<endl;
    else
        cout<<sum + vec[n-1]<<endl;
    return 0;
}