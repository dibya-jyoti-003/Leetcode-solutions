class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int len = nums.size();
        for (int i=0;i<len;i++){
            int copy = nums[i], sum = 0;
            while (copy>0){
                sum += copy%10;
                copy /= 10;
            }
            if (i == sum)return i;
        }
        return -1;
    }
};