#include<bits/stdc++.h>
using namespace std;
#define ar array
#define int long long  
const int M=1e9+7;
const int N=1001;
const int P= 31;
const int P1 =7919;

int32_t main(){
    
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n,m;
cin>>n>>m;

int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
vector<vector<int>>vis(n+1,vector<int>(m+1));

auto isValid=[&](int x,int y){
    if(x<0 || y<0 || x>=n || y>=m || vis[x][y])
    return 0;
    return 1;
};

function<void(int,int)> dfs=[&](int x,int y){
    vis[x][y]=1;
    
    for(int i=0;i<4;i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(isValid(nx,ny))
        dfs(nx,ny);
    }
};
}