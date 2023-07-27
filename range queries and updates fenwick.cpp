#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ar array
const int M=1e9+7;
const int N=3e5+5;
 
int32_t main(){
 
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n;
cin>>n;
vector<int>B1(n),B2(n);

auto add=[&](vector<int>& bit,int idx,int x){
    for(;idx<n;idx=idx|(idx+1))
    bit[idx]+=x;
};

auto sum=[&](vector<int>&bit,int r){
    int res=0;
    for(;r>=0;r=(r&(r+1))-1)
    res+=bit[r];
    return res;
};

auto range_add=[&](int l,int r,int x){
    add(B1, l, x);
    add(B1, r+1, -x);
    add(B2, l, x*(l-1));
    add(B2, r+1, -x*r);
};

auto prefix_sum=[&](int idx){
    return sum(B1, idx)*idx -  sum(B2, idx);
};
auto range_sum=[&](int l, int r){
    return prefix_sum(r) - prefix_sum(l-1);
};

range_add(0,2,3);
cout<<range_sum(0,2);
}


