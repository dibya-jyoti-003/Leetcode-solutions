#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
class Solution {
private:
    vvi ans ;
    void solve(vi temp,vi& nums,vb& vis){
        int len = nums.size();
        if (temp.size() == len){
            ans.push_back(temp);
            return ;
        }
        for (int i=0;i<len;i++){
            if (vis[i])continue;
            if (i>0 and nums[i]==nums[i-1] and !vis[i-1])continue;
            temp.push_back(nums[i]);
            vis[i]=true;
            solve(temp,nums,vis);
            vis[i] = false;
            temp.pop_back();
        }
    }
public:
    vvi permuteUnique(vi& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        vb vis(len,false);
        solve({},nums,vis);
        return ans ;
    }
};