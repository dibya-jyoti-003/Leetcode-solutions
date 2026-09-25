#define vi vector<int>
#define vvi vector<vi>
class Solution {
private :
    
    bool solve(string &s, int pos1, string &p, int pos2, vvi &dp){
        if (pos1<0){
            while (pos2>=0 and p[pos2]=='*')pos2 -= 2;
            if (pos2>=0)return false;
            return true ;
        }
        if (pos2<0)return false;
        if (dp[pos1][pos2] != -1)return dp[pos1][pos2];
        if (p[pos2] >= 'a' and p[pos2]<='z')return dp[pos1][pos2] = (s[pos1] == p[pos2] and solve(s,pos1-1,p,pos2-1,dp));
        if (p[pos2] == '.')return dp[pos1][pos2] = solve(s,pos1-1,p,pos2-1,dp);
        bool ans = false;
        ans = ans or solve(s,pos1,p,pos2-2,dp);
        if (p[pos2-1] == '.' or p[pos2-1] == s[pos1]) ans  = ans or solve(s,pos1-1, p,pos2,dp);
        return dp[pos1][pos2] = ans ;
    }
public:
    bool isMatch(string s, string p) {
        vvi dp(21,vector<int>(21,-1));
        return solve(s,s.size()-1, p, p.size()-1,dp) ;
    }
};