#include<bits/stdc++.h>
using namespace std;
#define ar array
#define int long long  
const int M=1e9+7;
const int N=3e5+5;
const int P= 31;
const int P1 =7919;

int32_t main(){
    
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int  n,q;
cin>>n>>q;

vector<vector<int>>par(n+1,vector<int>(31));
vector<vector<int>>g(n+1);

par[1][0]=1;

for(int i=2;i<=n;i++){
cin>>par[i][0];
g[i].push_back(par[i][0]);
g[par[i][0]].push_back(i);
}

for(int i=1;i<=30;i++){
    for(int u=1;u<=n;u++){
        par[u][i]=par[par[u][i-1]][i-1];
    }
}

vector<int>d(n+1);

function<void(int,int)> dfs=[&](int u,int p){
    
    for(auto v:g[u]){
        if(v==p)
        continue;
        d[v]=d[u]+1;
        dfs(v,u);
    }
};
d[1]=0;
dfs(1,0);

auto lca=[&](int u,int v){
    if(d[u]<d[v])
    swap(u,v);
    
    int dx=d[u]-d[v];


    for(int i=30;i>=0;i--){
        if(dx&(1<<i))
        {

         u=par[u][i];
        }
    }

    
    if(u==v)
    return u;
    
    for(int i=30;i>=0;i--){
        if(par[u][i]!=par[v][i]){
            u=par[u][i];
            v=par[v][i];
        }
    }
    return par[u][0];
};
while(q--){
int u,v;
cin>>u>>v;
cout<<lca(u,v)<<"\n";
}
}
