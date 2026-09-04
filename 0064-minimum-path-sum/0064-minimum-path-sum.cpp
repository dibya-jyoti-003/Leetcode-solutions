class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int dist[201][201];
        int m = grid.size(), n=grid[0].size();
        for (int i=0;i<=m;i++){
            for (int j=0;j<=n;j++)dist[i][j]=INT_MAX;
        }
        dist[m-1][n] = dist[m][n-1] = 0;
        for (int i=m-1;i>=0;i--){
            for (int j=n-1;j>=0;j--)dist[i][j] = grid[i][j] + min(dist[i+1][j], dist[i][j+1]);
        }
        return dist[0][0];
    }
};