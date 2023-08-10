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
 
// Main Idea = Store the starting and ending time of movies as vector of pairs. Then, sort the vector elements in ascending order of
// their ending time by making a custom function 'cmp'. Finally, while traversing the vector, if starting time of movie is greater
// than or equal to the previous movies' ending time, increement the number of movies watched by 1.
// Print the final answer.

// Time Complexity = O(n.logn + n), 'n.logn' to sort the vector, and 'n' to traverse throught the vector
// Space Complexity = O(n), to store the vector of pair.

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
    return (a.second < b.second);
}
int main()
{
    int n;
    cin>>n;
    vector<pair<int, int>> movies(n);
    for(int i=0; i<n; i++)
        cin>>movies[i].first>>movies[i].second;    
    sort(movies.begin(), movies.end(), cmp);
 
    int prev = -1;
    int i=0;
    int count = 0;
    while(i<n)
    {
        if(movies[i].first >= prev)
        {
            prev = movies[i].second;
            count++;
        }
        i++;
    }
    cout<<count<<endl;
    return 0;   
}