#define ll long long
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int len = nums.size();
        unordered_map<ll,ll> mp[1001];
        int result = 0;
        for (int i=1;i<len;i++){
            for (int j=0;j<i;j++){
                ll diff = 1LL * nums[i]- 1LL * nums[j];
                ll temp = (mp[j].find(diff)==mp[j].end())?0:mp[j][diff];
                mp[i][diff] += temp+1;
                result += temp;
            }
        }
        return result;
    }
};