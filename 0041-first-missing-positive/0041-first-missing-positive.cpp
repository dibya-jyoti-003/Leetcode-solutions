class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;){
            if (nums[i]>0 and nums[i]<=n and nums[i]-i != 1 and nums[nums[i]-1] != nums[i]){
                int temp = nums[i];
                nums[i]=nums[temp-1];
                nums[temp-1]=temp;
            }
            else i++;
        }
        int i=0;
        for (;i<n;i++){
            if (nums[i]-i != 1)break;
        }
        return i+1;
    }
};