class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int ans = 0, len = nums.size();
        for (int k=1;k<=len;k++){
            if (len % k != 0)continue;
            int start = 0,lastmax = INT_MIN;
            bool flag = false;
            while (start < len){
                int currmin = nums[start], currmax = nums[start], cnt = 0;
                for (int j = start+1; j<start + k;j++){
                    if (nums[j] < nums[j-1])cnt++;
                    if (cnt > 1){
                        flag = true;
                        break;
                    }
                    currmin = min(currmin,nums[j]);
                    currmax = max(currmax,nums[j]);
                }
                if (currmin<lastmax or (cnt==1 and nums[start+k-1]>nums[start]))flag = true ;
                if (flag)break;
                lastmax = currmax;
                start += k;
            }
            if (!flag)ans += k;
        }
        return ans ;
    }
};