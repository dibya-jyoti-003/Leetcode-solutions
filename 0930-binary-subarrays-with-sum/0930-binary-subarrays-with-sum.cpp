#define ll long long
#define vi vector<int>
class Solution {
private:
    ll solve(vi& nums, int goal){
        ll sum = 0, len=nums.size(),j=0, ans=0;
        for (int i=0;i<len;i++){
            sum += nums[i];
            while (sum > goal and j<=i)sum -= nums[j++];
            ans += i-j;
        }
        return ans ;
    }
public:
    int numSubarraysWithSum(vi& nums, int goal) {
        return (int)(solve(nums,goal)-solve(nums,goal-1));
    }
};