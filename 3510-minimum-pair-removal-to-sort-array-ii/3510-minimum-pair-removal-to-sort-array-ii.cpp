class Solution {
private: 
    typedef long long ll ;
    int prev_index[100002]={0}, next_index[100002]={0};
    set<pair<ll,int>> my_set;
    int badpair = 0;
public:
    int minimumPairRemoval(vector<int>& nums1) {
        int operation = 0,len = nums1.size();
        vector<ll> nums(len);
        for (int i=0;i<len;i++)nums[i]=nums1[i];
        for (int i=0;i<len-1;i++){
            prev_index[i] = i-1;
            next_index[i] = i+1;
            my_set.insert({nums[i]+nums[i+1],i});
            badpair += (nums[i]>nums[i+1]);
        }
        prev_index[len-1] = len-2;
        next_index[len-1] = len;
        while (badpair > 0){
            auto [sum,index] = *my_set.begin();
            my_set.erase({sum,index});
            int f = index, s = next_index[f], fl = prev_index[f], sr = next_index[s];
            badpair -= (nums[f] > nums[s]);
            if (fl >= 0) {
                my_set.erase({nums[fl]+nums[f],fl});
                my_set.insert({nums[fl]+sum,fl});
                if (nums[fl] <= nums[f] and nums[fl] > sum)badpair++;
                else if (nums[fl] > nums[f] and nums[fl] <= sum)badpair--;
            }
            if (sr < len) {
                my_set.erase({nums[s]+nums[sr],s});
                my_set.insert({sum+nums[sr],f});
                if (nums[s] <= nums[sr] and nums[sr] < sum)badpair++;
                else if (nums[s] > nums[sr] and nums[sr] >= sum)badpair--;
                prev_index[sr] = prev_index[s];
            }
            if (s<len) next_index[f] = next_index[s];
            operation++;
            nums[f] = sum ;
        }
        return operation ;
    }
};