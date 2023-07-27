#include<bits/stdc++.h>
using namespace std;
#define ar array
#define int long long  
const int M=1e9+7;
const int N=3e5+5;

int32_t main(){
    
ios_base::sync_with_stdio(false);
cin.tie(NULL);

string s,t;
cin>>s>>t;

vector<int>h(n+1);
h[0]=0;

int P=31;
vector<int>p(n+1);
p[0]=1;
for(int i=0;i<n;i++)
p[i+1]=p[i]*P%M;

for(int i=0;i<n;i++){
    h[i+1]=(h[i]+(s[i]-'a'+1)*p[i]%M)%M;
}

int cnt=0;

for(int l=1;l<=n;l++){
    set<int>st;
    for(int i=0;i+l-1<n;i++){
        int cur_h=(h[i+l]+M-h[i])%M*p[n-(i+1)]%M;
        st.insert(cur_h);
    }
    cnt+=st.size();
}
cout<<cnt<<"\n";
}
