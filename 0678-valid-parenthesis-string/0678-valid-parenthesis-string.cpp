#define vi vector<int>
#define vvi vector<vi>
#define vvvi vector<vvi>
class Solution {
private:
    bool solve(int open, int close ,int pos, string& s, vvvi& dp){
        if (pos == s.size())return open == close;
        if (close > open)return false;
        if (dp[open][close][pos] != -1)return dp[open][close][pos];
        if (s[pos] == '(')return solve(open+1,close,pos+1,s,dp);
        if (s[pos] == ')')return solve(open, close+1,pos+1,s,dp);
        bool empty_st = solve(open , close,pos+1,s,dp);
        if (empty_st)return dp[open][close][pos] = true ;
        bool open_br = solve(open+1,close,pos+1,s,dp);
        if (open_br)return dp[open][close][pos] = true;
        bool close_br = solve(open, close+1, pos+1,s,dp);
        return dp[open][close][pos] = close_br;
    }
public:
    bool checkValidString(string s) {
        vvvi dp(101,vvi(101,vi(101,-1)));
        return solve(0,0,0,s,dp);
    }
};