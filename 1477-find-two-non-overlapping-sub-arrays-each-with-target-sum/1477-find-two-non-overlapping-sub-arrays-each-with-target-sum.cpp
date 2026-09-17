class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int left=0, right=0, len=arr.size(),sum=0;
        int prefix[100001]={0}, suffix[100001]={0};
        while (right<len){
            sum += arr[right];
            while (left<right and sum > target)sum -= arr[left++];
            if (sum == target){
                prefix[right] = (!prefix[right])?right-left+1:min(prefix[right],right-left+1);
                sum -= arr[left++];
            }
            if(right<len-1)prefix[right+1]=prefix[right];
            right++;
        }
        left=right=len-1; sum = 0;
        while (left>=0){
            sum += arr[left];
            while (left<=right and sum > target)sum -= arr[right--];
            if (sum == target){
                suffix[left] = (!suffix[left])?right-left+1:min(suffix[left],right-left+1);
                sum -= arr[right--];
            }
            if (left>0)suffix[left-1]=suffix[left];
            left--;
        }
        int ans = INT_MAX;
        for (int i=0;i<len-1;i++){
            if (prefix[i]>0 and suffix[i+1]>0)ans=min(ans,prefix[i]+suffix[i+1]);
        }
        return (ans==INT_MAX)?-1:ans;
    }
};