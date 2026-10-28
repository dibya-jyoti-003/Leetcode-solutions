class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n=grid[0].size();
        const int X = 1024;
        vector<vector<bitset<X>>> dp(m,vector<bitset<X>>(n));
        dp[0][0].set(grid[0][0]);
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                int val = grid[i][j];
                if (i > 0) {
                    for (int x = 0; x < X; x++) if (dp[i-1][j][x])dp[i][j].set(x^val);
                }
                if (j > 0) {
                    for (int x = 0; x < X; x++) if (dp[i][j-1][x])dp[i][j].set(x^val);
                }
            }
        }
        for (int x = 0; x < X; x++) if (dp[m-1][n-1][x])return x;
        return -1;
    }
};

