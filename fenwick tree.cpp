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

vector<int>a(n);

for(int i=0;i<n;i++)
cin>>a[i];

vector<int>bit(n);

auto add=[&](int idx,int x){
    for(;idx<n;idx=idx|(idx+1))
    bit[idx]+=x;
};

auto sum=[&](int r){
    int res=0;
    for(;r>=0;r=(r&(r+1))-1)
    res+=bit[r];
    return res;
};

auto  query=[&](int l,int r)
{
    return sum(r)-(l-1>=0?sum(l-1):0);
};

for(int i=0;i<n;i++)
add(i,a[i]);


}








