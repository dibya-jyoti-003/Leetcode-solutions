#define ll long long
#define vi vector<int>
class Solution {
private:
    const ll MOD = 1e9 + 7;
    ll power(ll b, ll e) {
        ll r = 1;
        for (b %= MOD; e; e >>= 1, b = b * b % MOD)
            if (e & 1) r = r * b % MOD;
        return r;
    }
public:
    int numOfWays(vi& nums) {
        int n = nums.size();
        vi born(n + 2, -1);
        for (int i = 0; i < n; i++) born[nums[i]] = i;
        ll fact = 1, sizes = 1; 
        for (int k = 2; k <= n; k++) fact = (fact * k) % MOD;
        stack<int> st;
        st.push(0); 
        for (int v = 1; v <= n + 1; ++v) {
            while (born[st.top()] > born[v]) {  
                st.pop();
                sizes = sizes * (v - st.top() - 1) % MOD;  
            }
            st.push(v);
        }
        return (fact * power(sizes, MOD - 2) - 1 + MOD) % MOD;  
    }
};