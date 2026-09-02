class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for (int i=0;i<nums.size();i++){
            mp.insert({nums[i],i});
            if (mp.find(target-nums[i]) != mp.end()){
                if (mp[target-nums[i]] == i )continue;
                ans.push_back(mp[target-nums[i]]);
                ans.push_back(i);
                break;
            }
        }
        return ans ;
    }
};