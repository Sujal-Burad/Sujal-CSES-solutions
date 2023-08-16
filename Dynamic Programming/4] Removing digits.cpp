#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> // for map operations
#include<unordered_map>

// Main Idea = Subtract the maximum digit of the number from the number, everytime till the number = 0.

int maxdigit(int x)
{
    int maxi = x%10;
    while(x > 0)
    {
        maxi = max(maxi, x%10);
        x = x/10;
    }
    return maxi;
}
 
int main(){
   int n;
   cin>>n;
    int steps = 0;
    while(n > 0)
    {
        int maxd  = maxdigit(n);
        n = n - maxd;
        steps++;
    }
    cout<<steps<<endl;
    return 0;
}
