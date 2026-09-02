class Solution {
public:
    bool isPal(string &s,int start,int end){
        while (start <= end){
            if (s[start]!= s[end])return false;
            start++;end--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int pos1,pos2,maxi=INT_MIN,len = s.size();bool m = false;
        for (int i=0;i<len;i++){
            for (int j =len-1;j>=i;j--){
                if (m = isPal(s,i,j)){
                    if (maxi < (j-i)){
                        maxi = j-i;
                        pos1 = i;pos2=j;
                    }
                }
            }
        }
        string ans="";
        for (int p=pos1;p<=pos2;p++)ans = ans+s[p];
        return ans;
    }
};