class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size(), start=0,end=len-1;
        while (start <= end){
            int mid = start + (end-start)/2;
            if (nums[mid] == target)return mid;
            if (target > nums[mid])start = mid+1;
            else end = mid-1;
        }
        return start;
    }
};