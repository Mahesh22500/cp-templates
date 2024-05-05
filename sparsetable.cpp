#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ar array
const int M=1e9+7;
const int N=3e5+5;
 
int32_t main(){
 
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 
int n,q;
cin>>n>>q;
 
vector<int>a(n);
 
for(int i=0;i<n;i++)
cin>>a[i];
    
    vector<vector<int>>st(n,vector<int>(21));
    
    for(int i=0;i<n;i++)
    st[i][0]=a[i];
    
    for(int k=1;k<=20;k++){
        for(int i=0;i+(1<<k)-1<n;i++){
            st[i][k]=min(st[i][k-1],st[i+(1<<(k-1))][k-1]);
        
        }
    }

    auto query=[&](int a,int b){
        a--,b--;
        int dx=(b-a);
    int k=floor(log2(dx));
    int ans=min(st[a][k],st[b-(1<<k)+1][k]);
    return ans;
    };
 
while(q--){
int a,b;
cin>>a>>b;
a--,b--;
int dx=(b-a);
int k=floor(log2(dx));
int ans=min(st[a][k],st[b-(1<<k)+1][k]);
cout<<ans<<"\n";
}
}