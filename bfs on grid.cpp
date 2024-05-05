#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 5;

int32_t main()
{

   int n;
   cin>>n;

   vector<pair<int,int>>p;

   map<pair<int,int>,set<int>>mx,my;

   vector<int>vx,vy;

   for(int i=0;i<n;i++){
        
        int x,y;
        cin>>x>>y;
        p.push_back({x,y});
        vx.push_back(x);
        vy.push_back(y);
        

    

   }

   sort(vx.begin(),vx.end());
   sort(vy.begin(),vy.end());

  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        auto [x1,y1]=p1[i];
        auto [x2,y2]=p2[i];
        if(x1==x2)
        my[{y1,y2}].insert(x);
        if(y1==y2)
        mx[{x1,x2}].insert(y);
    }
  }

  

