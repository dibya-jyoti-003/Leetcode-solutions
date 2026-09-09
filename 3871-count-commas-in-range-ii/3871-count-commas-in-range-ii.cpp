#define ll long long
class Solution {
public:
    ll min(ll a, ll b){
        if (a<b)return a ;
        return b;
    }
    ll countCommas(ll n) {
        ll ans =0 , temp = 1e3;
        for (int i=0;i<5;i++){
            if (n>temp-1){
                ans += (min(n,temp*1000-1)-temp+1)*(i+1);
                temp *= 1000;
            }
        }
        return ans ;
    }
};