#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+5;
const int M=998244353;
int32_t main(){
 
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int tt;
cin>>tt;

while(tt--){

int n,k;
cin>>n>>k;

vector<int>b(n),c(n);

for(int i=0;i<n;i++)
cin>>b[i];

for(int i=0;i<n;i++)
cin>>c[i];

vector<int>cost(N);

cost[1]=0;

for(int i=1;i<N;i++)
{
    for(int j=1;j<=i;j++){ 
        cost[i+i/j]=min(cost[i+i/j],cost[i]+1);
    }
}

vector<int>dp(k+1,-1e18);
dp[0]=0;

for(int i=0;i<n;i++){
    for(int j=k;j>=0;j--){
        if(j-cost[b[i]]>=0)
        dp[j]=max(dp[j],c[i]+dp[j-cost[b[i]]]);
    }
}
cout<<dp[k]<<"\n";
}
}

