#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ar array
const int M=1e9+7;
const int N=3e5+5;
 
int32_t main(){
 
ios_base::sync_with_stdio(false);
cin.tie(NULL);


int n,m;
cin>>n>>m;

vector<vector<int>>a(n,vector<int>(m));
for(int i=0;i<n;i++)
for(int j=0;j<m;j++)
cin>>a[i][j];

vector<vector<int>>bit(n,vector<int>(m));


auto sum=[&](int x,int y){
int res=0;
for(int i=x;i>=0;i=(i&(i+1))-1){
    for(int j=y;j>=0;j=(j&(j+1))-1)
    res+=bit[i][j];
}
return res;
};

auto add=[&](int x,int y,int v){
for(int i=x;i<n;i=i|(i+1))
for(int j=y;j<m;j=j|(j+1))
bit[i][j]+=v;
};

auto query=[&](int x1,int y1,int x2,int y2){
    return sum(x2,y2)-(y1-1>=0?sum(x2,y1-1):0)-(x1-1>=0?sum(x1-1,y2):0)+(x1-1>=0 && y1-1>=0?sum(x1-1,y1-1):0);
};

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        add(i,j,a[i][j]);
}
}

cout<<query(0,0,1,1);
}