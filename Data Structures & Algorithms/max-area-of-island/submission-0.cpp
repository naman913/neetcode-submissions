class Solution {
public:
    int area(vector<vector<int>>& grid,vector<vector<int>>& visited,int n,int m ,int i,int j,vector<pair<int,int>>&direction){
        int curr_area=1;
        for(int k=0;k<4;k++){
            int dx=i+direction[k].first;
            int dy=j+direction[k].second;
            if(dx>=0&&dy>=0&&dx<n&&dy<m&&visited[dx][dy]==0&&grid[dx][dy]==1){
                visited[dx][dy]=1;
                curr_area+=area(grid,visited,n,m,dx,dy,direction);
            }
        }
        return curr_area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<pair<int,int>>direction={{1,0},{-1,0},{0,1},{0,-1}};
        int maxcnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==0&&grid[i][j]==1){
                    visited[i][j]=1;
                    maxcnt=max(maxcnt,area(grid,visited,n,m,i,j,direction));
                }
            }
        }
        return maxcnt;
    }
};
