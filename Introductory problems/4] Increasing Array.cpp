#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> 

// Main Idea = Update the current element, whenever it is less than the previous one.
// Keep adding the difference between in a variable called 'final'.

// Time Complexity = O(n)
// Space Complexity = O(1), i.e constant

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    long long final = 0;
    for(int i=1; i<n; i++)
    {
        if(arr[i] >= arr[i-1])
            continue;
        
        else
        {
            final = final + arr[i-1]-arr[i];
            arr[i] = arr[i-1];
        }
    }
    cout<<final<<endl;
    return 0;
}