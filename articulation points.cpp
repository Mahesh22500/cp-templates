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

while(1){ 
    

int  n,m;
cin>>n>>m;
if(n==0 && m==0)
break;
vector<vector<int>>g(n+1);

for(int i=0;i<m;i++){
int u,v;
cin>>u>>v;
g[u].push_back(v);
g[v].push_back(u);
}

vector<int>vis(n+1),in(n+1),low(n+1);
int timer=0;
set<int>cuts;

function<void(int,int)> dfs=[&](int u,int p){
vis[u]=1;
in[u]=low[u]=timer++;
int c=0;
for(auto v:g[u]){

    if(v==p)
    continue;
    if(vis[v]){
        low[u]=min(low[u],in[v]);
    }
    else{
        dfs(v,u);
        c++;
        if(low[v]>=in[u] && p!=0){
           cuts.insert(u);
        }
        low[u]=min(low[u],low[v]);
    }
}

if(p==0 && c>1)
cuts.insert(u);
};

for(int i=1;i<=n;i++){
if(!vis[i])
dfs(i,0);
}
cout<<cuts.size()<<"\n";
}
}



