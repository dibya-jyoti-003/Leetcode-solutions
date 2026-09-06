#define ll long long
class Solution {
public:
    int numDistinct(string s, string t) {
        int len1=s.size(),len2=t.size();
        unsigned ll dp[1001][1001]={0};
        for (int row = 0;row<=len1;row++)dp[row][len2]=1;
        for (int row = len1-1;row>=0;row--){
            for (int col = len2-1;col>=0;col--){
                dp[row][col] = dp[row+1][col];
                if (s[row]==t[col])dp[row][col] += dp[row+1][col+1];
            }
        }
        return dp[0][0];
    }
};