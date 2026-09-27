class Solution {
private:
    double solve(double x, int n, unordered_map<int,double>& mp){
        if (n==0)return 1;
        if (n==1)return x;
        if (mp.find(n) != mp.end())return mp[n];
        mp[n] = solve(x,n/2,mp) * solve(x,n-n/2,mp);
        return mp[n];
    }
public:
    double myPow(double x, int n) {
        unordered_map<int,double> mp;
        int offset = 0;
        if (n == INT_MIN){
            offset = -1;
            n++;
        }
        double ans = solve(x,abs(n),mp);
        if (n<0)ans = 1/ans ;
        if (offset != 0)ans = ans/x;
        return ans ;
    }
};