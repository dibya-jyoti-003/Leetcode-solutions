#define ll long long
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int bit[31] = {0}, len = nums.size(), mod =1e9+7;
        for (int i=0;i<len;i++){
            for (int j = 0;j<31;j++)bit[30-j] += (nums[i] & (1<<j))>0;
        }
        ll ans = 0;
        while (k--){
            int temp = 0;
            for (int i=30;i>=0;i--){
                if (bit[i] > 0){
                    bit[i]--;
                    temp = (temp | (1<<(30-i)))%mod;
                }
            }
            ans  = (ans + (1LL * temp * temp)%mod)%mod;
        }
        return (int)ans ;
    }
};