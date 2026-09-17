class Solution {
private:
    int lnum = 1e5+1;
    int solve(string& s, int pos , int l){
        int len = s.size();
        if (pos == len)return lnum;
        int r = solve(s,pos+1,(s[pos]=='R')?1:(s[pos]=='L')?lnum:l+1);
        int ret = (s[pos]=='L')?1:(s[pos]=='R')?lnum:r+1;
        if (s[pos]=='.'){
            if (l<=len and l<r)s[pos]='R';
            if (r<=len and l>r)s[pos]='L';
        }
        return ret;
    }
public:
    string pushDominoes(string dominoes) {
        solve(dominoes,0,lnum);
        return dominoes;
    }
};