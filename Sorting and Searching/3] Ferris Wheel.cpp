#include<bits/stdc++.h>
#define ll  long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> // for map operations
#include<unordered_map>
// #define mod 1000000007
#include <algorithm>
 
//  Main Idea = First sort the arrays of weight in ascending order and use the two pointer technique
// , then for each gondola we can do:
// 1] Pair the lightest child with the heaviest child without exceeding the weight limit.
// 2] If the pairing isn't possible, then take a different gondola for the heavier child.
// Those who are not paired get their own gondola.

// Time Complexity = O(n) for two pointer method and O(n.logn) for the sorting method. Hence, the overall 
// time complexity = O(n.logn)

int main()
{
    int n, max;
    cin>>n>>max;
    int weight[n];
    for(int i=0; i<n; i++)  cin>>weight[i];
    sort(weight, weight + n);
    int count = 0;
    int i=0, j=n-1;
    while(i<=j)
    {
        if(weight[i] + weight[j] <= max)
        {
            count++;
            i++;
            j--;
        }
        else
        {
            j--;
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}