class Solution {
public:
    int calc (int a){
        return 3 + ((a+1)*(a-4))/2;
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size()<3)return 0;
        int left = 0, right = 1, diff = nums[right]-nums[left], len = nums.size(),ans=0;
        while (right < len){
            if (nums[right]-nums[right-1] == diff){
                right++;
                continue;
            }
            ans += calc(right-left);
            left = right-1;
            diff = nums[right++]-nums[left];
        }
        ans += calc(right-left);
        return ans ;
    }
};