#include<bits/stdc++.h>
using namespace std;
#define ar array
#define int long long  
const int M=1e9+7;
const int N=3e5+5;
const int P= 31;
const int P1 = 7919;
int32_t main(){
    
ios_base::sync_with_stdio(false);
cin.tie(NULL);

//No of occurences of a string in a text

string t;
cin>>t;



string s;
cin>>s;

int n=t.size();
int m=s.size();


string S=s+'#'+t;
int N=S.size();

vector<int>pi(N);

pi[0]=0;

for(int i=1;i<N;i++){
    int j=pi[i-1];

    while(j!=1 && s[j]!=s[j])
    j=pi[j-1];

    if(s[i]==s[j])
    {
        j++;
        pi[i]=j;
    }
}

int cnt=0;

for(int i=m+1;i<N;i++){
    if(p[i]==m)
    cnt++;
}

cout<<cnt<<"\n";
}