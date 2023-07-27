#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ar array
const int K=700;
const int N=1e7+5;
const int M=1e9+7;

struct Node{
    Node* links[26];
    int cnt=0;
};

int32_t main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);

Node* root=new Node();

auto Insert=[&](string& s){
    Node* node=root;
    
    for(int i=0;i<s.size();i++){
        if(node->links[s[i]-'a']==NULL){
            node->links[s[i]-'a']=new Node();
        }
        node=node->links[s[i]-'a'];
        node->cnt++;
    }
};

auto Delete=[&](string& s){
    Node* node=root;
    for(int i=0;i<s.size();i++){
        node=node->links[s[i]-'a'];
        node->cnt--;
    }
};

auto Query=[&](string& s){
    Node* node = root;
    int res=0;
    for(int i=0;i<s.size();i++){
        if(node->links[s[i]-'a']==NULL){
            break;
        }
        node=node->links[s[i]-'a'];
        if(node->cnt==0)
        break;
        res++;
    }
    
    return res;
    
};


int n;
cin>>n;
vector<string>v(n);

for(int i=0;i<n;i++)
cin>>v[i];

for(int i=0;i<n;i++)
Insert(v[i]);

for(int i=0;i<n;i++){
    Delete(v[i]);
    int ans=Query(v[i]);
    cout<<ans<<"\n";
    Insert(v[i]);
}
}

























