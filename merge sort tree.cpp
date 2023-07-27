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


vector<vector<int>>st(4*n+5);


function<void(int,int,int)> build=[&](int si,int l,int r){
    if(l==r){
        st[si].push_back(a[l]);
        return;
    }
    
    int m=(l+r)/2;
    
    build(2*si+1,l,m);
    build(2*si+2,m+1,r);
    
    vector<int>&a=st[2*si+1];
    vector<int>&b=st[2*si+2];
    
    int n1=a.size(),n2=b.size();
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(a[i]<b[j])
        st[si].push_back(a[i++]);
        else
        st[si].push_back(b[j++]);
    }
    while(i<n1)
    st[si].push_back(a[i++]);
    while(j<n2)
    st[si].push_back(b[j++]);
};


function<int(int,int,int,int,int,int)> query=[&](int si,int l,int r,int ql,int qr,int x){
    if(l>qr || r<ql)
    return (long  long )1e10;
    
    if(l>=ql && r<=qr){
        auto it=lower_bound(st[si].begin(),st[si].end(),x);
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


