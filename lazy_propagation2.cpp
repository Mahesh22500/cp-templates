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
 
int  n;
cin>>n;
 
vector<int>a(n+1);
 
for(int i=1;i<=n;i++)
cin>>a[i];
 
vector<int>st(4*n+5),lazy(4*n+5);
 
function<void(int,int,int)> build=[&](int si,int l,int r){
    if(l==r){
        st[si]=a[l];
        return;
    }
    int m=(l+r)/2;
    build(2*si+1,l,m);
    build(2*si+2,m+1,r);
    st[si]=max(st[2*si+1],st[2*si+2]);
};
 
function<void(int,int,int,int,int,int)> update=[&](int si,int l,int r,int ql,int qr,int x){
 
if(lazy[si]){
    if(l!=r){
    st[2*si+1]=st[2*si+2]=st[si];
    lazy[2*si+1]=1;
    lazy[2*si+2]=1;
    }
    lazy[si]=0;
}
 
 
     if(l>qr || r<ql)
    return;
    
    if(l>=ql && r<=qr)
    {
        st[si]=x;
        lazy[si]=1;
        return;
    }
    
    int m=(l+r)/2;
    
    update(2*si+1,l,m,ql,qr,x);
    update(2*si+2,m+1,r,ql,qr,x);
    st[si]=max(st[2*si+1],st[2*si+2]);
};
 
function<int(int,int,int,int,int)> query=[&](int si,int l,int r,int ql,int qr){
if(lazy[si]){
    if(l!=r){
    st[2*si+1]=st[2*si+2]=st[si];
    lazy[2*si+1]=1;
    lazy[2*si+2]=1;
    }
    lazy[si]=0;
} 
    if(l>qr || r<ql){ 
    return 0LL;
    }
    if(l>=ql && r<=qr)
    return st[si];
    
    
    
    int m=(l+r)/2;
    
    int left=query(2*si+1,l,m,ql,qr);
    int right=query(2*si+2,m+1,r,ql,qr);
    
    return max(left,right);
    
};
build(0,1,n);
 
 
 
int m;
cin>>m;
 
vector<int>ans(m);
 
for(int i=0;i<m;i++){
    int w,h;
    cin>>w>>h;
    
    ans[i]=query(0,1,n,1,w);
    update(0,1,n,1,w,ans[i]+h);
    
}
for(int i=0;i<m;i++)
cout<<ans[i]<<"\n";
}