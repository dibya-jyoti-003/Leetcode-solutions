class Solution {
public:
    int dp[501][501];
    int solve(string &st, int left, int right){
        if (left >= right)return 0;
        if (dp[left][right] != -1)return dp[left][right];
        if (st[left] == st[right])return solve(st,left+1, right-1);
        return dp[left][right] = 1+min(solve(st,left+1,right), solve(st,left,right-1));
    }
    int minInsertions(string s) {
        int n = s.size();
        for (int i=0;i<=500;i++){
            for (int j=0;j<=500;j++)dp[i][j]=-1;
        }
        return solve(s,0,n-1);
    }
};