#define vi vector<int>
class Solution {
private:
    int ans = 0;
    void solve(int rem,int pos, vi &nums){
        int len = nums.size();
        if (pos >= len){
            ans += (!rem);
            return ;
        }
        solve(rem+nums[pos],pos+1,nums);
        solve(rem-nums[pos],pos+1,nums);
    }
public:
    int findTargetSumWays(vi& nums, int target) {
        solve(target,0,nums);
        return ans ;
    }
};