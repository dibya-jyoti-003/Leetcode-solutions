class Solution {
public:
    typedef long long  ll;
    int minOperations(vector<int>& nums, int x) {
        ll sum = accumulate(nums.begin(), nums.end(),0), len = nums.size();
        x = sum - x;
        if (x<0)return -1;
        if (x == 0)return len;
        ll right = 0, left = 0, curr = 0, ans = INT_MIN;
        while (right < len){
            curr += 1LL * nums[right];
            while (curr > x)curr -= nums[left++];
            if (curr == x)ans = max(ans, right-left);
            right++;
        }
        return (ans<0)?-1:(int)(len-ans-1) ;
    }
};