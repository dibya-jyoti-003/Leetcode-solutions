#define ll long long
class Solution {
public:
    vector<ll> resultArray(vector<int>& nums, int k) {
        vector<ll> ans(k,0) ;
        int len = nums.size();
        for (int& num:nums)num %= k;
        for (int rem = 0;rem<k;rem++){
            ll res = 0;
            ll temp[5]={0};
            for (int pos = 0;pos<len;pos++){
                res += (nums[pos]%k == rem);
                ll curr[5]={0};
                for (int p=0;p<k;p++)if ((nums[pos]*p)%k == rem)res += temp[p];
                for (int j=0;j<k;j++)curr[(j*nums[pos])%k] += temp[j];
                for (int j=0;j<k;j++)temp[j]=curr[j];
                temp[nums[pos]]++;
            }
            ans[rem] = res;
        }
        return ans;
    }
};