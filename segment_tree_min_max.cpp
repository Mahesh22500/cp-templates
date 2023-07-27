#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6+5;
const int M=1e9+7;



int32_t main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);


int n,m;
cin>>n>>m;

vector<int>a(n);

for(int i=0;i<n;i++)
cin>>a[i];

vector<int>st_max(4*n+5);
vector<int>st_min(4*n+5);

map<int,vector<int>>mp;

for(int i=0;i<n;i++)
mp[a[i]].push_back(i);

auto max_combine=[&](int a,int b){
            return  max(a,b);
        };
        
function<void(int,int,int)> max_build=[&](int si,int l,int r){
            if(l==r){
                st_max[si]=a[l];
                return;
            }
            
            int m=(l+r)/2;
            max_build(2*si+1,l,m);
            max_build(2*si+2,m+1,r);
            
            st_max[si]=max_combine(st_max[2*si+1],st_max[2*si+2]);
            
        };
        

        
function<int(int,int,int,int,int)> max_query=[&](int si,int l,int r,int ql,int qr){
            if(l>=ql && r<=qr)
                return st_max[si];
            
            if(l>qr || r<ql)
                return 0LL;
            
            int m=(l+r)/2;
            int op1=max_query(2*si+1,l,m,ql,qr);
            int op2=max_query(2*si+2,m+1,r,ql,qr);
            return max_combine(op1,op2);
        };
        
max_build(0,0,n-1);




auto min_combine=[&](int a,int b){
            return  min(a,b);
        };
        
function<void(int,int,int)> min_build=[&](int si,int l,int r){
            if(l==r){
                st_min[si]=a[l];
                return;
            }
            
            int m=(l+r)/2;
            min_build(2*si+1,l,m);
            min_build(2*si+2,m+1,r);
            
            st_min[si]=min_combine(st_min[2*si+1],st_min[2*si+2]);
            
        };
        

        
function<int(int,int,int,int,int)> min_query=[&](int si,int l,int r,int ql,int qr){
            if(l>=ql && r<=qr)
                return st_min[si];
            
            if(l>qr || r<ql)
                return (long long)1e18;
            
            int m=(l+r)/2;
            int op1=min_query(2*si+1,l,m,ql,qr);
            int op2=min_query(2*si+2,m+1,r,ql,qr);
            return min_combine(op1,op2);
        };
        
min_build(0,0,n-1);




while(m--){

int l,r,x;
cin>>l>>r>>x;

l--,r--;

int mx=max_query(0,0,n-1,l,r);
int mn=min_query(0,0,n-1,l,r);

if(mx==mn && mx==x){
    cout<<-1<<"\n";
    continue;
}

if(mn!=x){

int pos=lower_bound(mp[mn].begin(),mp[mn].end(),l)-mp[mn].begin();
cout<<mp[mn][pos]+1<<"\n";


}
else{
 
 int pos=lower_bound(mp[mx].begin(),mp[mx].end(),l)-mp[mx].begin();
cout<<mp[mx][pos]+1<<"\n";
   
}
}
}












