#define ll long long
class Solution {
private:
    ll min(ll a ,ll b){
        if (a<b)return a ;
        return b;
    }
public:
    int maxProfit(vector<int>& inv, int k) {
        sort(inv.begin(), inv.end());
        ll sum = 0, len = inv.size(), ans = 0, lps, mod = 1e9+7;
        for (auto i:inv)sum += i;
        sum -= k;
        for (int i=0;i<len;i++){
            lps = sum/(len-i);
            ll temp = min(inv[i], lps);
            if (temp != inv[i])ans += ((1LL*inv[i]*(inv[i]+1))/2)%mod - ((1LL*temp*(temp+1))/2)%mod;
            sum -= temp;
        }
        return (int)((ans % mod + mod) % mod);
    }
};