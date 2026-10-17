class Solution {
private:
    int getsum(int a){
        int sum = 0;
        while (a > 0){
            sum += a%10;
            a /= 10;
        }
        return sum;
    }
public:
    int minSwaps(vector<int>& nums) {
        vector<int> sorted(nums);
        int ans = 0, len = nums.size();
        unordered_map<int,int> mp;
        for (int i=0;i<len;i++)mp[nums[i]] = i;
        sort(sorted.begin(), sorted.end(), [this](int a,int b){
            int sa = getsum(a),sb = getsum(b);
            if (sa != sb)return sa<sb;
            return a<b;
        });
        for (int i=0;i<len;i++){
            if (sorted[i] != nums[i]){
                ans++;
                swap(nums[i], nums[mp[sorted[i]]]);
                mp[nums[mp[sorted[i]]]] = mp[sorted[i]];
            }
        }
        return ans;
    }
};