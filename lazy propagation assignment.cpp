#include<bits/stdc++.h>
using namespace std;
#define ar array
#define int long long  


int32_t main(){
    
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n,m;
cin>>n>>m;

vector<int>st(4*n+5),lazy(4*n+5);
 
function<void(int,int,int,int,int,int)> update=[&](int si,int l,int r,int ql,int qr,int x){

     if(l>qr || r<ql)
    return;
    
    if(l>=ql && r<=qr)
    {
        lazy[si]=1;
        st[si]=x;
        return;
    }

    if(lazy[si]){
    st[2*si+1]=st[2*si+2]=st[si];
    lazy[2*si+1]=lazy[2*si+2]=1;
    lazy[si]=0;
}
    int m=(l+r)/2;
    
    update(2*si+1,l,m,ql,qr,x);
    update(2*si+2,m+1,r,ql,qr,x);
    
};
 
function<int(int,int,int,int)> query=[&](int si,int l,int r,int idx){
    if(l==r){
        return st[si];
    }
    
if(lazy[si]){
    st[2*si+1]=st[2*si+2]=st[si];
    lazy[2*si+1]=lazy[2*si+2]=1;
    lazy[si]=0;
}
   
    int m=(l+r)/2;
    if(idx<=m)
    return query(2*si+1,l,m,idx);
    else
    return query(2*si+2,m+1,r,idx);
    
};

vector<ar<int,3>>v;
for(int i=0;i<m;i++){
    int l,r,x;
    cin>>l>>r>>x;
    v.push_back({l,r,x});
}

for(int i=m-1;i>=0;i--){
    auto &[l,r,x]=v[i];
    int cur=query(0,1,n,x);
    update(0,1,n,l,r,x);
    update(0,1,n,x,x,cur);
}

for(int i=1;i<=n;i++)
{
    int ans=query(0,1,n,i);
    cout<<ans<<" ";
}
}








