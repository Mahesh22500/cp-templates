#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ar array
const int M=1e9+7;
const int N=3e5+5;
 
int32_t main(){
 
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 
int  n,q;
cin>>n>>q;
 
vector<int>a(n),st(4*n+5);
 
for(int i=0;i<n;i++)
cin>>a[i];
 
auto combine=[&](int a,int b){
            return a+b;
        };
        
function<void(int,int,int)> build=[&](int si,int l,int r){
            if(l==r){
                st[si]=a[l];
                return;
            }
            
            int m=(l+r)/2;
            build(2*si+1,l,m);
            build(2*si+2,m+1,r);
            
            st[si]=combine(st[2*si+1],st[2*si+2]);
            
        };
        
function<void(int,int,int,int,int)> update=[&](int si,int l,int r,int qi,int x){
            if(l==r){
                a[l]=x;
                st[si]=x;
                return;
            }
            int m=(l+r)/2;
            if(qi<=m)
                update(2*si+1,l,m,qi,x);
            else
                update(2*si+2,m+1,r,qi,x);
            st[si]=combine(st[2*si+1],st[2*si+2]);
        };
        
function<int(int,int,int,int,int)> query=[&](int si,int l,int r,int ql,int qr){
            if(l>=ql && r<=qr)
                return st[si];
            
            if(l>qr || r<ql)
                return 0LL;
            
            int m=(l+r)/2;
            int op1=query(2*si+1,l,m,ql,qr);
            int op2=query(2*si+2,m+1,r,ql,qr);
            return combine(op1,op2);
        };
        
build(0,0,n-1);
while(q--){
int c;
cin>>c;
if(c==2){
    int l,r;
    cin>>l>>r;
    l--,r--;
    int ans=query(0,0,n-1,l,r);
    cout<<ans<<"\n";
}
else{
    int k,x;
    cin>>k>>x;
    k--;
    update(0,0,n-1,k,x);
}
}
}