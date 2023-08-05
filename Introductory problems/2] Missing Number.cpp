#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> 

// Using exclusive OR (XOR) to solve this
// Main Idea =  Doing XOR of a number with itself returns zero
 
int main(){
	ll n; cin>>n;
    int xornum=0, x=0;
    for(int i=1; i<=n; i++)     xornum^=i;
    for(int i=1; i<n; i++)  cin>>x, xornum^=x;
    cout<<xornum<<endl;
	return 0;
}