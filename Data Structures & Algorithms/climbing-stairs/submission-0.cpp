class Solution {
public:
    int climbStairs(int n) {
        vector<int>visited(n+1,0);
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        visited[1]=1;
        visited[2]=2;
        for(int i=3;i<=n;i++){
            visited[i]=visited[i-1]+visited[i-2];
        }
        return visited[n];
    }
};
