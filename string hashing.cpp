#include<bits/stdc++.h>
using namespace std;
#define ar array
#define int long long  
const int M=1e9+7;
const int N=3e5+5;

int32_t main(){
    
ios_base::sync_with_stdio(false);
cin.tie(NULL);

auto compute=[&](string& s){
    const int P=37;
    int hash=0;
    int p=1;
    
    for(auto c:s){
        hash=(hash+(c-'a'+1)*p%M)%M;
        p=p*P%M;
    }
    return hash;
};

string s,t;
cin>>s>>t;

cout<<compute(t)<<"\n";
cout<<compute(s)<<"\n";
// int n;
// cin>>n;
// vector<string>a;
// vector<ar<int,2>>v;
// for(int i=0;i<n;i++){
//     string s;
//     cin>>s;
//     a.push_back(s);
//     int res=compute(s);
//     v.push_back({res,i});
// }

// sort(v.begin(),v.end());

// vector<vector<int>>groups;
// groups.emplace_back();
// groups.back().push_back(v[0][1]);
// for(int i=1;i<n;i++){
//     if(v[i][0]==v[i-1][0]){
//         groups.back().push_back(v[i][1]);
//     }
//     else{
//         groups.emplace_back();
//         groups.back().push_back(v[i][1]);
//     }
// }
// for(auto v1:groups){
//     for(auto i:v1)
//     cout<<a[i]<<" ";
//     cout<<"\n";
// }
}
