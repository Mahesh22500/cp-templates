#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
const int N=1e3+5;
char grid[N][N];
int a[N][N];
int p[N][N];
 
int main(){
    int n,q;
    cin>>n>>q;
     int m=n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='.')
            a[i][j]=0;
            else 
            a[i][j]=1;
            
        }
    }
vector<vector<int>>p(n,vector<int>(m));

for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        p[i][j]=(i-1>=0?p[i-1][j]:0)+ (j-1>=0?p[i][j-1]:0)-(i-1>=0 && j-1>=0 ? p[i-1][j-1]:0)+(v[i][j]=='W');
    }
}

auto get=[&](int i1,int j1,int i2,int j2){
    return p[i2][j2]-(j1-1>=0?p[i2][j1-1]:0)-(i1-1>=0?p[i1-1][j2]:0)+(i1-1>=0 && j1-1>=0?p[i1-1][j1-1]:0);
};


    while(q--){
       int l1,r1,l2,r2;
       cin>>l1>>r1>>l2>>r2;
        cout<<p[l2][r2]-p[l2][r1-1]-p[l1-1][r2]+p[l1-1][r1-1]<<"\n";
    }
    
    
}