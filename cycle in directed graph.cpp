class Solution {
public:
    int longestCycle(vector<int>& edges) {
        
        
    int  n=edges.size();
        vector<vector<int>>g(n);
        for(int i=0;i<n;i++){
            if(edges[i]==-1)
                continue;
            
            g[i].push_back(edges[i]);
        }
        
        int len=0;
        vector<int>vis(n);
        vector<int>onStack(n);
        function<bool(int)> dfs=[&](int u){
            vis[u]=1;
            onStack[u]=1;
            for(auto v:g[u]){
                if(vis[v]){
                    if(onStack[v]){
                        int  l=1;
                        int x=edges[v];
                        while(x!=v){
                            l++;
                            x=edges[x];
                        }
                        
                        len=l;
                         onStack[u]=0;
                        return 1;
                    }
                   
                }
                if(!vis[v]){
                if(dfs(v)){ 
                     onStack[u]=0;
                    return 1;
                }
                }
                
            }
            onStack[u]=0;
            return 0;
            
            
        };
        
        int ans=-1;
        for(int i=0;i<n;i++){
            if(!vis[i]){
           bool cyc=dfs(i);
            if(cyc){
                ans=max(ans,len);
            }
        }
        }
        return ans;
    }
};