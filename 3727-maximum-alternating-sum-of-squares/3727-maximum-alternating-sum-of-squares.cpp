#define ll long long
class Solution {
public:
    ll maxAlternatingSum(vector<int>& nums) {
        sort (nums.begin(), nums.end(),[](const int a, const int b){
            return abs(a) < abs(b);
        });
        ll ans = 0;
        int left = 0, right = nums.size()-1;
        while (left<right){
            ans += (1LL * nums[right] * nums[right])-(1LL * nums[left] * nums[left]);
            right--;
            left++;
        }
        if (left == right)ans += 1LL * nums[left] * nums[right];
        return ans;
    }
};