#include<bits/stdc++.h>
using namespace std;
int main(){

int n;
cin>>n;

vector<int>a(n);

for(int i=0;i<n;i++)
cin>>a[i];


vector<int>p(n),s(n);

p[0]=1;
s[n-1]=1;
for(int i=1;i<n;i++){
    if(p[i]>p[i-1])
    p[i]=p[i-1]+1;
    else
    p[i]=1;
}

for(int i=n-2;i>=0;i--){
    if(s[i]<s[i+1])
    s[i]=s[i+1]+1;
    else
    s[i]=1;
}


int ans=max(p[n-1],s[0]);

for(int i=0;i<n;i++){
    if((i-1>=0?a[i-1]:0)<(i+1<n?a[i+1]:1e10))
    ans=max(ans,(i-1>=0?p[i-1]:0)+(i+1<n?s[i+1]:0));
}

cout<<ans;
}
