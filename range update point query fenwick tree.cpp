#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ar array
const int M=1e9+7;
const int N=3e5+5;
 
int32_t main(){
 
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int  n,m,c;
cin>>n>>m>>c;

vector<int>bit(n);

auto add=[&](int idx,int x){
    for(;idx<n;idx=idx|(idx+1))
    bit[idx]+=x;
};

auto sum=[&](int r){
    int res=0;
    for(;r>=0;r=(r&(r+1))-1)
    res+=bit[r];
    return res;
};

auto  query=[&](int l,int r)
{
    return sum(r)-(l-1>=0?sum(l-1):0);
};

auto range_add=[&](int l,int r,int x){
    add(l,x);
    if(r+1<n)
    add(r+1,-x);
};

range_add(0,n-1,c);

while(m--){
char c;
cin>>c;
if(c=='S'){
int u,v,k;
cin>>u>>v>>k;
u--,v--;
range_add(u,v,k);
}
else{
int p;
cin>>p;
p--;
int ans=sum(p);
cout<<ans<<"\n";
}
}
}

