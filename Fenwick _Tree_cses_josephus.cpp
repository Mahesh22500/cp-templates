#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ar array
const int K=700;
const int N=1e7+5;
const int M=1e9+7;
int32_t main(){
 
struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;
 
    FenwickTree(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }
 
    FenwickTree(vector<int> a)
        : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
 
    int sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
 
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
 
    void add(int idx, int delta) {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
};
 
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 
int n,k;
cin>>n>>k;
k++;
 
FenwickTree st(n);
 
for(int i=0;i<n;i++)
st.add(i,1);
 
vector<int>a(n);
 
for(int i=0;i<n;i++)
a[i]=1;
 
vector<int>ans;
 
int pos=0;
for(int i=0;i<n;i++){
    
    int have=st.sum(pos,n-1);
    int tot=st.sum(0,n-1);
    
    if(have>=k){
    int l=pos-1,r=n-1;
    
    while(r>l+1){
        int m=(l+r)/2;
        int cur=0;
        if(pos>=0)
        cur=st.sum(pos,m);
 
        if(cur>=k)
        r=m;
        else
        l=m;
    }
    
    
    pos=r;
    st.add(pos,-1);
 
   
    ans.push_back(pos+1);
    }
    else{
        int k1=k;
        k-=have;
        k%=tot;
        if(k==0)
        k=tot;
        int l=-1,r=n-1;
    
    while(r>l+1){
        int m=(l+r)/2;
        int cur=0;
        if(pos>=0)
        cur=st.sum(0,m);
        
        if(cur>=k)
        r=m;
        else
        l=m;
    }
    
    k=k1;
    pos=r;
    st.add(pos,-1);
  
    ans.push_back(pos+1);
    
    }
    
}
 
for(auto x:ans)
cout<<x<<" ";
cout<<"\n";
}