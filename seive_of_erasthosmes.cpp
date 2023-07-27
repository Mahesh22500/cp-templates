#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ar array
//const int M=998244353;
const int M=1e9+7;
const int N=2e6+5;
 
int32_t main(){

vector<int>isPrime(N,1);

isPrime[1]=0;
for(int i=2;i*i<N;i++){
    if(isPrime[i]){
    for(int j=i*i;j<N;j+=i)
    isPrime[j]=0;
    }
}

vector<int>cnt(N);
for(int i=2;i<N;i++){
    cnt[i]=cnt[i-1];
    if(isPrime[i] && isPrime[(i+1)/2])
    cnt[i]++;
}


int q;
cin>>q;

while(q--){
    int l,r;
    cin>>l>>r;
    
    cout<<cnt[r]-cnt[l-1]<<"\n";
}
}