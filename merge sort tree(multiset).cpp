#include<bits/stdc++.h>
using namespace std;
#define ar array
#define int long long  

int32_t main(){
    
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n;
cin>>n;

vector<int>a(n);

for(int i=0;i<n;i++)
cin>>a[i];


vector<multiset<int>>st(4*n+5);


function<void(int,int,int)> build=[&](int si,int l,int r){
    if(l==r){
        st[si].insert(a[l]);
        return;
    }
    
    int m=(l+r)/2;
    
    build(2*si+1,l,m);
    build(2*si+2,m+1,r);
    
    for(auto &x:st[2*si+1])
    st[si].insert(x);
    
    for(auto& x:st[2*si+2])
    st[si].insert(x);
    
};

function<void(int,int,int,int,int)> update=[&](int si,int l,int r,int idx,int x){
    if(l==r){
        st[si].erase(a[idx]);
        st[si].insert(x);
        a[idx]=x;
        return;
    }
    st[si].erase(a[idx]);
    st[si].insert(x);
    int m=(l+r)/2;
    if(idx<=m)
    {
        update(2*si+1,l,m,idx,x);
    }
    else{
        update(2*si+2,m+1,r,idx,x);
    }
};


function<int(int,int,int,int,int,int)> query=[&](int si,int l,int r,int ql,int qr,int x){
    if(l>qr || r<ql)
    return (long  long )1e10;
    
    if(l>=ql && r<=qr){
        auto it=st[si].lower_bound(x);
        if(it!=st[si].end())
        return *it;
        else
        return (long long ) 1e10;
    }
    
    int m=(l+r)/2;
    
    int left=query(2*si+1,l,m,ql,qr,x);
    int right=query(2*si+2,m+1,r,ql,qr,x);
    
    return min(left,right);
};

build(0,0,n-1);
}

