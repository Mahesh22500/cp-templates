class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
     queue<array<int,3>>q;
        vector<vector<int>>ans(n,vector<int>(m));
        vector<vector<int>>vis(n,vector<int>(m));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    ans[i][j]=0;
                    q.push({i,j,0});
                }
            }
        }
        
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
      
        auto isValid=[&](int x,int y){
    if(x<0 || y<0 || x>=n || y>=m || vis[x][y])
    return 0;
    return 1;
};
        
        while(!q.empty())
        {
            auto [x,y,d]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(isValid(nx,ny)){
                    ans[nx][ny]=d+1;
                    vis[nx][ny]=1;
                    q.push({nx,ny,d+1});
                }
            }
        }
        
        return ans;
    }
};