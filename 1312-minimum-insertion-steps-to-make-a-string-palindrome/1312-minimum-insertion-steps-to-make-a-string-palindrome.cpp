class Solution {
public:
    
    int minInsertions(string st) {
        int dp[501][501],n = st.size();
        for (int i=0;i<n;i++)dp[i][i]=0;
        for (int i=n-2;i>=0;i--){
            for (int j=i+1;j<n;j++){
                if (st[i] == st[j])dp[i][j] = dp[i+1][j-1];
                else dp[i][j] = 1+min(dp[i+1][j], dp[i][j-1]);
            }
        }
        return dp[0][n-1];
    }
};