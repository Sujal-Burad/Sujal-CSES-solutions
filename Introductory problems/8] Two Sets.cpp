#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> 

// Main Idea = First check if the sum of numbers is even or odd. If its odd simply print "NO", since it cannot be divided int two
// sets with equal sum
// If the sum is even, follow the below conditions in the code, depending on whether given number is even or odd.


int main(){
   long long test;
   cin>>test;
   long long sum = test*(test+1)/2;
//    cout<<sum;
//    return 0;
   if(sum %2== 1)
        cout<<"NO"<<endl;
    else
    {
        if(test % 2 == 0)
        {
            cout<<"YES"<<endl;
            cout<<test/2<<endl;
            for(int i=1; i<=test/2; i+=2)
                cout<<i<<" ";
            for(int i=test; i>test/2; i-=2)
                cout<<i<<" ";
            
            cout<<test/2<<endl;
            for(int i=2; i<=test/2; i+=2)
                cout<<i<<" ";
            for(int i=test-1; i>test/2; i-=2)
                cout<<i<<" ";
            
        }
        else
        {
 
            cout<<"YES"<<endl;
            sum = sum/2;
            vector<long long> first;
            long long n= test;
            vector<bool> two(n+1, true);
            long long last = n;
            while(sum!=0)
            {
                if(sum >= last)
                {
                    first.push_back(last);
                    two[last] = false;
                    sum = sum - last;
                    last--;
                }
                else
                {
                    first.push_back(sum);
                    two[sum] = false;
                    break;
                }
            }
            cout<<first.size()<<endl;
            for(auto x:first) cout<<x<<" ";
            cout<<endl;
            cout<<n-first.size()<<endl;
            for(long long i=1; i<=n; i++)
                if(two[i] == true)
                    cout<<i<<" ";
            cout<<endl;
        }
    }
 
  return 0;
}
