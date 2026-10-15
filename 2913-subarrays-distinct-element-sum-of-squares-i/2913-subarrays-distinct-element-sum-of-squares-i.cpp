class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int len = nums.size(), ans = len;
        for (int i=2;i<=len;i++){
            int count = 0;
            unordered_map<int,int> mp;
            for (int j=0;j<i;j++){
                if (mp.find(nums[j]) == mp.end()){
                    mp[nums[j]]=1;
                    count++;
                }
                else mp[nums[j]]++;
            }
            ans += count*count;
            for (int j=i;j<len;j++){
                if (mp.find(nums[j]) == mp.end())mp[nums[j]] = 1;
                else mp[nums[j]]++;
                if (mp[nums[j]] == 1)count++;
                mp[nums[j-i]]--;
                if (!mp[nums[j-i]])count--;
                ans += count*count;
            }
        }
        return ans ;
    }
};