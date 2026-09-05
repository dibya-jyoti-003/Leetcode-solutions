class Solution {
public:
    int minCut(string st) {
        int len = st.size();
        bool pal[2001][2001]={0};
        for (int j = 0; j < len; j++) {
            for (int i = 0; i <= j; i++) {
                if (st[i] == st[j] and (j<i+3 or pal[i+1][j-1])) pal[i][j] = true;
            }
        }
        int dp[2001];
        for (int i = 0; i < len; i++) {
            if (pal[0][i]) {
                dp[i] = 0;
                continue;
            }
            dp[i] = i;
            for (int j = 0; j < i; j++) {
                if (pal[j + 1][i]) dp[i] = min(dp[i], dp[j] + 1);
            }
        }
        return dp[len - 1];
    }
};