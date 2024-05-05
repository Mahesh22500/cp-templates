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

int  n,m;
cin>>n>>m;

vector<vector<ar<int,2>>>g(n+1);

for(int i=0;i<m;i++){
    int u,v,x;
    cin>>u>>v>>x;
    g[u].push_back({v,x});
    g[v].push_back({u,x});
}


vector<int>min_d(n+1,1e18);
min_d[1]=0;
priority_queue<ar<int,2>,vector<ar<int,2>>,greater<ar<int,2>>>q;

q.push({0,1});

while(!q.empty()){
    auto [d,u]=q.top();
    q.pop();
    if(min_d[u]<d)
    continue;
    
    for(auto [v,x]:g[u]){
        if(d+x<min_d[v]){
            min_d[v]=d+x;
            q.push({min_d[v],v});
        }
    }
}
for(int i=1;i<=n;i++)
cout<<min_d[i]<<" ";
}


int s=mp[]

