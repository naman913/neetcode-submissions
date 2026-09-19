class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),-1));
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==-1&&grid[i][j]=='1'){
                    queue<pair<int,int>>q;
                    count++;
                    q.push({i,j});
                    visited[i][j]=1;
                    while(q.size()){
                        auto z=q.front();
                        q.pop();
                        int x=z.first;
                        int y=z.second;
                        pair<int,int> dz[4]={{-1,0},{0,1},{1,0},{0,-1}};
                        for(int k=0;k<4;k++){
                            int dx=x+dz[k].first;
                            int dy=y+dz[k].second;
                            if(dx>=0&&dy>=0&&dx<n&&dy<m&&visited[dx][dy]==-1&&grid[dx][dy]=='1'){
                                visited[dx][dy]=1;
                                q.push({dx,dy});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};
