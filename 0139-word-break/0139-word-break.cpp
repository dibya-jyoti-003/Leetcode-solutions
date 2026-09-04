class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool dp[301];
        int len = s.size(),temp = len;
        dp[len]=true ;
        while (temp >0){
            for (int i=temp-1;i>=0;i--){
                string st = s.substr(i,temp-i);
                if (find(wordDict.begin(),wordDict.end(),st) != wordDict.end())dp[i]=true ;
            }
            temp--;
            while (temp>0 and !dp[temp])temp--;
        }
        return dp[0];
    }
};