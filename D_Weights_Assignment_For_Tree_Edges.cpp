#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e3+5;
const int M=998244353;
int32_t main(){
 
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int tt;
cin>>tt;


while(tt--){


int n;
cin>>n;

vector<int>b(n+1);

for(int i=1;i<=n;i++)
cin>>b[i];

vector<int>p(n+1);

for(int i=1;i<=n;i++)
cin>>p[i];


vector<int>vis(n+1);

int root;

for(int i=1;i<=n;i++){
    if(i==b[i])
    root=i;
}

if(p[1]!=root){
    cout<<-1<<"\n";
    continue;
}
vis[p[1]]=1;
bool ok=1;

for(int i=2;i<=n;i++){
    if(!vis[b[p[i]]]){
        ok=0;
        break;
    }
    vis[p[i]]=1;
}

if(!ok){
    cout<<-1<<"\n";
    continue;
}

vector<int>ans(n+1),dis(n+1);

dis[p[1]]=0;
ans[p[1]]=0;

for(int i=2;i<=n;i++){
    ans[p[i]]=dis[p[i-1]]+1;
    dis[p[i]]=dis[p[i-1]]+ans[p[i]];
}

for(int i=1;i<=n;i++)
cout<<ans[i]<<" ";
cout<<"\n";
}
}
