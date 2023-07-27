#include <bits/stdc++.h>
using namespace std;
#define int long long
const int K = 700;
const int N = 2e5 + 5;
const int M = 1e9 + 7;


int32_t main()
{  
   vector<int>isPrime(N,1);

isPrime[1]=0;
for(int i=2;i*i<N;i++){
    if(isPrime[i]){
    for(int j=i*i;j<N;j+=i)
    isPrime[j]=0;
    }
}
   
   int n;
   cin>>n;

   vector<pair<int,int>>edges;
   vector<vector<int>>g(n+1);


   vector<pair<int,int>>p0,p1,p2;

   for(int i=0;i<n-1;i++){
      int u,v;
      cin>>u>>v;
      g[u].push_back(v);
      g[v].push_back(u);
      if(isPrime[u] && isPrime[v])
      p2.push_back({u,v});
      else
      if(isPrime[u] || isPrime[v])
      p1.push_back({u,v});
      else
      p0.push_back({u,v});
   }

   vector<int>par(n+1);

   for(int i=1;i<=n;i++)
{
   par[i]=i;
   
}
   function<int(int)> find=[&](int u){
    if(par[u]==u)
    return u;
    return par[u]=find(par[u]);
};

function<void(int,int)> unite=[&](int u,int v){
    par[u]=v;
};


vector<int>siz(n+1);

for(int i=1;i<=n;i++)
siz[i]=1;

int ans=0;

for(auto [u,v]:p0){
   u=find(u);
   v=find(v);
   if(u==v)
   continue;

   par[u]=v;
   siz[v]+=siz[u];
}

for(int i=1;i<=n;i++)
cout<<i<<" "<<siz[i]<<"\n";

function<void(int u,int p)> dfs=[&](int u, int p){
      int leaf=1;
      for(auto v:g[u]){
         if(v==p)
         continue;

         leaf=0;
         
         if(!isPrime[p]  && !isPrime[v] && isPrime[u]){
           ans+=(siz[p]+1)*(siz[v]+1);
         }
      }

      if(leaf){
         if(isPrime[u] && !isPrime[p])
         ans+=siz[u]+1;
      }
};

dfs(1,0);

cout<<ans<<"\n";
}

