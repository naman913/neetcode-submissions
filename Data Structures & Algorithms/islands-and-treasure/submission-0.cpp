class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<vector<int>>distance(n,vector<int>(m,-1));
        queue<pair<int,int>>pq;
        int number = INT_MAX;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==0)
                {
                    pq.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
        int ans =0;
        while(pq.size()){
            int k = pq.size();
            while(k--){
                auto top = pq.front();
                int x = top.first;
                int y = top.second;
                distance[x][y]=ans;
                pq.pop();
                // 1,0
                if(x+1>=0&&x+1<n&&y>=0&&y<m&&grid[x+1][y]==number&&visited[x+1][y]==0){
                    visited[x+1][y]=1;
                    pq.push({x+1,y});
                }
                // 0,1
                if(x>=0&&x<n&&y+1>=0&&y+1<m&&grid[x][y+1]==number&&visited[x][y+1]==0){
                    visited[x][y+1]=1;
                    pq.push({x,y+1});
                }
                // -1,0
                if(x-1>=0&&x-1<n&&y>=0&&y<m&&grid[x-1][y]==number&&visited[x-1][y]==0){
                    visited[x-1][y]=1;
                    pq.push({x-1,y});
                }
                // 0,-1
                if(x>=0&&x<n&&y-1>=0&&y-1<m&&grid[x][y-1]==number&&visited[x][y-1]==0){
                    visited[x][y-1]=1;
                    pq.push({x,y-1});
                }
            }
            ans++;
        }
        
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==number&&distance[i][j]==-1)
                    grid[i][j]=number;
                else 
                    grid[i][j]=distance[i][j];
            }
        }
        return;
        
    }
};
