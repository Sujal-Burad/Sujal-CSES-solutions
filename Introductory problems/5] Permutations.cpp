#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> 

// Main Idea : The beautiful permutation cannot exist for array whose size is <= 3.
// To print the permutation we can, first simply print the even numbers and then the odd numbers.

// Time Complexity = O(n)
// Space Complexity = O(1), since we are not storing anything.

int main(){
    int n;
    cin>>n;
    if(n==1)
        cout<<"1"<<endl;
    else if(n <= 3)
        cout<<"NO SOLUTION"<<endl;
    
    else
    {
        //even
        for(int i=2; i<=n; i = i+2)
            cout<<i<<" ";
        for(int i=1; i<=n; i+=2)
            cout<<i<<" ";
    }
    return 0;
}