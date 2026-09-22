class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int len=nums.size();
        while (!is_sorted(nums.begin(), nums.begin()+len)){
            int mini = nums[0]+nums[1] , pos = 0;
            for (int i=1;i<len-1;i++){
                if (nums[i]+nums[i+1] < mini){
                    mini = nums[i]+nums[i+1];
                    pos = i;
                }
            }
            nums[pos]=mini;
            for (int i=pos+1;i<len-1;i++)nums[i]=nums[i+1];
            len--;
        }
        return nums.size()-len;;
    }
};