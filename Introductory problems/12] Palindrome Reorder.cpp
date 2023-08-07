#include<bits/stdc++.h>
#define ll long long
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
#include<map> 
#include<unordered_map>

// Main Idea = Firstly, count all the occurences of all the characters. 
// The string cannot be a palindrome if the count of odd occurences is greater than 1 or equal to 1 and the
// length of string is even.
// Store the palindrome in two string: firsthalf, and secondhalf. For every character with count as count, 
// attach count/2 characters to the end of firsthalf and beginning of the secondhalf.
// Finally return the result by appending firsthalf and secondhalf.
// Also, insert the odd character if there is any.

// Time complexity = O(n)
// Space complexity = O(1), constant 

int main(){
  string s;
  cin>>s;
    unordered_map<char, int> mpp;
    int s_size = s.length();

    for(int i=0; i<s_size; i++)
        mpp[s[i]]++;
    
    int oddcount = 0;
    char oddchar;
    for(auto it : mpp)
    {
        if(it.second % 2 != 0)
        {
            oddcount++;
            oddchar = it.first;
        }
    }
 
    if(oddcount >1 || (oddcount == 1 && s.length()%2 == 0))
        cout<<"NO SOLUTION"<<endl;
    
    else
    {
        string firsthalf = "", secondhalf = "";
        for(auto it : mpp)
        {
            string s(it.second/2, it.first);
 
            firsthalf = firsthalf + s;
            secondhalf = s + secondhalf;
        }
        string final;
        if(oddcount == 1)
            final = firsthalf + oddchar + secondhalf;
        
        else
            final = firsthalf + secondhalf;
        
        cout<<final<<endl;
    }
  return 0;
}