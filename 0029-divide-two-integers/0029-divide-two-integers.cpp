#define ll long long
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 1 or dividend == 0)return dividend;
        if (divisor == -1)return (dividend == INT_MIN)?INT_MAX:0-dividend;
        int sign1 = (dividend<0)?-1:1, sign2 = (divisor < 0)?-1:1;
        ll dv = abs((ll)(dividend));
        ll ds = abs((ll)(divisor));
        ll ans = -1;
        while (dv >= 0){
            dv -= ds;
            ans++;
        }
        if (sign1 != sign2)ans = 0-ans ;
        return (int)(ans) ;
    }
};