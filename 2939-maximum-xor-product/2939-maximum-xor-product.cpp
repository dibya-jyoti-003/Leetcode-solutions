
#define ll long long
class Solution {
public:
    int maximumXorProduct(ll a, ll b, int n) {
        ll num= 0, MOD = 1e9+7  ,temp;
        for (int i=n-1;i>=0;i--){
            bool a_bit = (a>>i) & 1, b_bit = (b>>i) & 1;
            if (a_bit == b_bit or (a^num) <= (b^num))temp = (1LL * (!a_bit))<<i;
            else temp =(1LL *(!b_bit))<<i;
            num = num | temp;
        }
        return (((a^num)%MOD)*((b^num)%MOD))%MOD;
    }
};