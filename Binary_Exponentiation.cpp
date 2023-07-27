#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ar array
const int M=1e9+7;
const int N=3e5+5;
 
int32_t main(){
 
ios_base::sync_with_stdio(false);
cin.tie(NULL);

vector<int>fact(N);
fact[0]=1;

for(int i=1;i<N;i++)
fact[i]=fact[i-1]*i%M;

auto P=[&](int a,int b){
    int res=1;

    while(b){
        if(b&1)
        res=res*a%M;
        a=a*a%M;
        b=b>>1;
    }
    return res;
};

auto MI=[&](int a){
    return P(a,M-2);
};
}
}