#define vs vector<string>
class Solution {
private:
    vs ans ;
    void solve(int pos, string temp, string &s, vs& dict){
        int len = s.size();
        if (pos == len){
            ans.push_back(temp);
            return ;
        }
        for (int i=1;i<=len-pos;i++){
            string st = s.substr(pos,i);
            if (find(dict.begin(),dict.end(),st) != dict.end()){
                string next = temp+st;
                if (pos+i<len)next = next + " ";
                solve(pos+i,next,s,dict);
            }
        }
    }

public:
    vs wordBreak(string s, vs& wordDict) {
        solve(0,"",s,wordDict);
        return ans ;
    }
};