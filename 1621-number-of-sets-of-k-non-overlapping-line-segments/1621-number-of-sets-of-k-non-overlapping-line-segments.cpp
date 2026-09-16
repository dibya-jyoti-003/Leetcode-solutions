#define ll long long
class Solution {
public:
    int numberOfSets(int n, int k) {
        ll dp[1001][1001]={0}, mod = 1e9+7;
        for (ll i=1;i<n;i++){
            dp[i][1] = (((i+1)*i)/2)%mod;
            dp[i][i] = 1;
        }
        for (int j=2;j<=k;j++){
            for (int i=j+1;i<n;i++){
                dp[i-1][j-1] = (dp[i-1][j-1] + dp[i-2][j-1])%mod;
                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1])%mod;
            }
        }
        return (int)dp[n-1][k];
    }
};