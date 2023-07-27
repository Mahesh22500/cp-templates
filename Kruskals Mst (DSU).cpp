#include<bits/stdc++.h>
using namespace std;
#define ar array
#define int long long  
const int M=1e9+7;
const int N=3e5+5;
const int P= 31;
const int P1 =7919;



int32_t main()
    
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n,m;
cin>>n>>m;


vector<ar<int,3>>edges;

for(int i=0;i<m;i++){
cin>>u>>v>>w;
int u,v,w;
edges.push_back({u,v,w});
}


auto cmp=[&](ar<int,3>a,ar<int,3>b){
    return a[2]<b[2];
};

sort(edges.begin(),edges.end(),cmp);




vector<int>par(n+1);
for(int i=1;i<=n;i++)
par[i]=i;

function<int(int)> find=[&](int u){
    if(par[u]==u)
    return u;
    return par[u]=find(par[u]);
};

function<void(int,int)> unite=[&](int u,int v){
    par[u]=v;
};

int ans=0;
for(auto [u,v,w]:edges){
    u=find(u);
    v=find(v);
    if(u==v)
    continue;
    
    ans+=w;
    unite(u,v);
}
cout<<ans<<"\n";




