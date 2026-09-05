#define vs vector<string>
class Solution {
private:
    vs ans;
    int calc(string &s, int start, int end){
        int val = 0;
        for (int i=start;i<=end;i++){
            val = val*10 + (s[i]-'0');
        }
        return val;
    }
    void solve(int pos, string& s, string temp, int cnt){
        int len = s.size();
        if (cnt == 3){
            int val = calc(s,pos,len-1);
            if (len-pos>3 or pos >= len or val>255 or (len-pos>1 and s[pos]=='0'))return ;
            temp = (len-pos==3)?temp+s.substr(pos,3):(len-pos==2)?temp+s.substr(pos,3):temp+s[pos];
            ans.push_back(temp);
            return ;
        }
        if (pos<len-1)solve(pos+1,s,temp+s[pos]+'.',cnt+1);
        if (pos+1<len-1 and s[pos]!='0'){
            solve(pos+2,s,temp+s[pos]+s[pos+1]+'.',cnt+1);
        }
        if (pos+2<len-1 and s[pos]!='0' and calc(s,pos,pos+2)<256){
            solve(pos+3,s,temp+s[pos]+s[pos+1]+s[pos+2]+'.',cnt+1);
        }
    }
public:
    vs restoreIpAddresses(string s) {
        int len = s.size();
        if (len<4 or len>12 )return {};
        solve(0,s,"",0);
        return ans ;
    }
};