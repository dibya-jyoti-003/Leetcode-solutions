class Solution {
public:
    int sumOfPower(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        vector<long long> dp(k + 1, 0);
        dp[0] = 1;
        for (int x : nums) {
            for (int s = k; s >= 0; s--) {
                dp[s] = (2 * dp[s]) % MOD;
                if (s >= x) dp[s] = (dp[s] + dp[s - x]) % MOD;
            }
        }
        return (int)(dp[k]);
    }
};