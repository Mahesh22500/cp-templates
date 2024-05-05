#include<bits/stdc++.h>
using namespace std;
#define ar array
#define int long long  
const int M=1e9+7;
const int N=3e5+5;
const int P= 31;
const int P1 =7919;



int32_t main(){
    
ios_base::sync_with_stdio(false);
cin.tie(NULL);


int n;
cin>>n;

vector<int>a(n);

for(int i=0;i<n;i++)
cin>>a[i];

int ans=0;

for(auto x:a){
    int mn=10;

    while(x){
        mn=min(mn,x%10);
        x/=10;
    }

    ans+=mn;
}

cout<<ans;
}


