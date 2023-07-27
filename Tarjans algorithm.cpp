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

vector<vector<int>>g(n+1);

for(int i=1;i<=m;i++){
    int u,v;
    cin>>u>>v;
    g[u].push_back(v);

}

vector<int>vis(n+1);

vector<int>tin(n+1),low(n+1),onStack(n+1);
stack<int>st;
int timer=0;
vector<int>b;

function<void(int)> dfs=[&](int u){
    vis[u]=1;
    tin[u]=low[u]=timer++;
    onStack[u]=1;
    st.push(u);
    for(auto v:g[u]){
        if(vis[v] && onStack[v]){
            low[u]=min(low[u],tin[v]);
        }
        else
        if(!vis[v]){
            dfs(v);
            if(onStack[v]){
                low[u]=min(low[u],low[v]);
            }
        }
    }
    if(low[u]==tin[u]){
       int v;
       while(1){
           v=st.top();
           st.pop(),onStack[v]=0;
           cout<<v<<" ";
           if(u==v)
           break;
       }
       
       cout<<"\n";
    }
    
};

dfs(1);

}
