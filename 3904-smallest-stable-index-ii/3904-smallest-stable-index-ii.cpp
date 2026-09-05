class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxi[100001]={0},mini[100001]={0};
        int len=nums.size();
        maxi[0]=nums[0];
        mini[len-1]=nums[len-1];
        for (int i=1;i<len;i++){
            maxi[i]=max(maxi[i-1],nums[i]);
            mini[len-i-1]=min(mini[len-i],nums[len-i-1]);
        }
        for (int i=0;i<len;i++)if (maxi[i]-mini[i]<=k)return i;
        return -1;
    }
};