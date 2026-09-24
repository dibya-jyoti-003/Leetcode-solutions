class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size(), pos = len-1, offset = 0;
        while (pos>0 and nums[pos]<=nums[pos-1])pos--;
        if (pos > 0){
            int left = pos-1;
            for (pos = len-1;nums[pos]<=nums[left];pos--);
            swap(nums[left], nums[pos]);
            offset = left+1;
        }
        reverse(nums.begin()+offset, nums.end());
    }
};