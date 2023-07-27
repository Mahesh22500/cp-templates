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


string s,t;
cin>>s>>t;

auto compute=[&](string& s){

    int hash=0;
    int p=1;
    
    for(auto c:s){
        hash=(hash+(c-'a'+1)*p%M)%M;
        p=p*P%M;
    }
    return hash;
};

int hsh=compute(s);
int m=s.size();
int n=t.size();
vector<int>h(n+1);
h[0]=0;


vector<int>p(n+1);
p[0]=1;
for(int i=0;i<n;i++)
p[i+1]=p[i]*P%M;

for(int i=0;i<n;i++){
    h[i+1]=(h[i]+(t[i]-'a'+1)*p[i]%M)%M;
}


vector<int>ans;

for(int i=0;i+m-1<n;i++){
    int cur=(h[i+m]+M-h[i])%M;
   
    if(hsh*p[i]%M==cur){
     ans.push_back(i+1);   
    }
}