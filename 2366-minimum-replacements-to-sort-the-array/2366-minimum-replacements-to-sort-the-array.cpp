#define ll long long
class Solution {
public:
    ll minimumReplacement(vector<int>& nums) {
        int n =  nums.size(), prev = nums[n-1];
        ll ans =0 ;
        for (int i=n-2;i>=0;i--){
            int freq = nums[i]/prev;
            if (nums[i] % prev != 0){
                freq++;
                prev = nums[i]/freq;
            }
            ans += freq-1;
        }
        return ans ;
    }
};