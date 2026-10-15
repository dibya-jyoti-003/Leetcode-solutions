class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int len = nums.size(), ans = len;
        for (int i=2;i<=len;i++){
            int count = 0;
            unordered_map<int,int> mp;
            for (int j=0;j<i;j++){
                mp[nums[j]]++;
                count += (mp[nums[j]] == 1);
            }
            ans += count*count;
            for (int j=i;j<len;j++){
                mp[nums[j]]++;
                count += (mp[nums[j]] == 1) - (--mp[nums[j-i]] == 0);
                ans += count*count;
            }
        }
        return ans ;
    }
};