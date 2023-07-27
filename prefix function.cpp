#include<bits/stdc++.h>
using namespace std;
#define ar array
#define int long long  
const int M=1e9+7;
const int N=3e5+5;
const int P= 31;
const int P1 = 7919;
int32_t main(){
    
ios_base::sync_with_stdio(false);
cin.tie(NULL);

string s;
cin>>s;

int n=s.size();

vector<int>pi(n);
auto prefix_function=[&](string& s){
for(int i=1;i<n;i++){
    int j=pi[i-1];
    
    while(j>0 && s[j]!=s[i])
    j=pi[j-1];
    
    if(s[j]==s[i])
    j++;
    
    pi[i]=j;
}
};

prefix_function(s);
for(int i=0;i<n;i++)
cout<<pi[i]<<" ";
}