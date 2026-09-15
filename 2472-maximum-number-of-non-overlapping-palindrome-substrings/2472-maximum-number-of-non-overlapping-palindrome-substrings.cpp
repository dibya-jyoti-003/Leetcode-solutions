class Solution {
public:
    int maxPalindromes(string s, int k) {
        bool pal[2001][2001]={0};
        vector<int> arr[2001];
        int len = s.size();
        int dp[2002]={0};
        for (int end=0;end<len;end++){
            for (int start =end;start>=0;start--){
                if (s[start] == s[end]){
                    if (end-start<=2) pal[start][end] = true;
                    else pal[start][end] = pal[start+1][end-1];
                    if (pal[start][end] and end-start >= k-1)arr[end].push_back(start);
                }
            }
        }
        for (int i=0;i<len;i++){
            for (int j:arr[i])dp[i+1] = max(dp[i+1], 1+dp[j]);
            dp[i+1] = max(dp[i+1],dp[i]);
        }
        return dp[len];
    }
};