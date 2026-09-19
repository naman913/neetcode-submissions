class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,-1));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                    visited[i][j]=0;
                }
            }
        }
        vector<pair<int,int>>direction={{1,0},{-1,0},{0,1},{0,-1}};
        int sum=0;
        while(q.size()!=0){ 
            sum++;
            int count=q.size();
            while(count--){
                auto z=q.front();
                    q.pop();
                    for(int i=0;i<4;i++){
                        int dx=z.first+direction[i].first;
                        int dy=z.second+direction[i].second;
                        if(dx>=0&&dy>=0&&dx<n&&dy<m&&visited[dx][dy]==-1&&grid[dx][dy]==INT_MAX){
                            visited[dx][dy]=sum;
                            q.push({dx,dy});
                    }
                }
            }
        } 

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (grid[i][j] != -1) {
                    grid[i][j]=visited[i][j] == -1 ? 2147483647 : visited[i][j];
                }
            }
        }       
    }
};
