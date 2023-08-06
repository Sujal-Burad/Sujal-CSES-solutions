#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> 

// Main Idea : The output to be printed is done by making observation.
// Time and Space Complexity = O(1), i.e constant

int main(){
   int test;
   cin>>test;
   for(int tt=1; tt<=test; tt++)
   {
        long long x, y;
        cin>>x>>y;
        if(x==y)
            cout<<x*x - (x-1)<<endl;
        else
        {
            if(x%2==0)
            {
                if(y<=x)
                    cout<<x*x - (y-1)<<endl;
                else
                {
                    if(y%2!=0)
                        cout<<y*y - (x-1)<<endl;
                    else
                        cout<<(y-1)*(y-1)+1 +(x-1)<<endl; 
                }
            }
            else
            {
                if(y<=x)
                    cout<<(x-1)*(x-1)+1 + (y-1)<<endl;
                else
                {
                    if(y%2!=0)
                        cout<<y*y - (x-1)<<endl;
                    else
                        cout<<(y-1)*(y-1)+1 +(x-1)<<endl; 
                }
            }
        }
   }
    return 0;
}