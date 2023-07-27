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

int n,m;
cin>>n>>m;

vector<vector<int>>g(n+1),g1(n+1);

for(int i=1;i<=m;i++){
    int u,v;
    cin>>u>>v;
    g[u].push_back(v);
    g1[v].push_back(u);

}

vector<int>vis(n+1);
vector<int>order;
function<void(int)> dfs=[&](int u){
    vis[u]=1;
    
    for(auto v:g[u]){
        if(!vis[v])
        dfs(v);
    }
    order.push_back(u);
};


for(int i=1;i<=n;i++){
    if(!vis[i])
    dfs(i);
}

vector<vector<int>>scc;

reverse(order.begin(),order.end());
vis.clear();
vis.resize(n+1);

function<void(int)> dfs1=[&](int u){
    vis[u]=1;
    scc.back().push_back(u);
    for(auto v:g1[u]){
        if(!vis[v])
        dfs1(v);
    }
};

for(auto x:order){
    if(!vis[x]){ 
    scc.emplace_back();
    dfs1(x);
    }
}

for(auto& v:scc){
    for(auto x:v)
    cout<<x<<" ";
    cout<<"\n";
}

}

