#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
 
int main(){
	ll n; cin>>n;
	while(n!=1){
		cout<<n<<" ";
		if((n&1)==1)  n=n*3+1;
		else n/=2;
	}
	cout<<1<<" ";
	return 0;
}
