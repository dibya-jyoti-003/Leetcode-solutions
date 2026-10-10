#define ll long long 
#define vi vector<int>
class Solution {
public:
    ll minSumSquareDiff(vi& nums1, vi& nums2, int k1, int k2) {
        int diff[100001]={0};
        ll k = (ll)k1 + k2, sum = 0;
        int mx = 0;
        for (int i = 0; i < nums1.size(); i++) {
            int x = abs(nums1[i] - nums2[i]);
            diff[x]++;
            sum += x;
            mx = max(mx, x);
        }
        if (sum <= k) return 0;
        for (int i = mx; i > 0 && k > 0; i--) {
            ll move = min(k, (ll)diff[i]);
            diff[i] -= move;
            diff[i-1] += move;
            k -= move;
        }
        ll ans = 0;
        for (int i = 0; i <= mx; i++)ans += (ll)i * i * diff[i];
        return ans;
    }
};