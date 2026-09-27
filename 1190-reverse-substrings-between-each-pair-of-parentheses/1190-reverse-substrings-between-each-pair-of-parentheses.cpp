class Solution {
public:
    string reverseParentheses(string s) {
        unordered_map<int,int> brackets;
        int len = s.size();
        stack<int> st;
        stack<pair<int,int>> st2;
        for (int i=0;i<len;i++){
            if (s[i] == '(')st.push(i);
            else if (s[i] == ')'){
                brackets[i] = st.top();
                brackets[st.top()] = i;
                st.pop();
            }
        }
        string ans = "";
        st2.push({-1,len});
        while (!st2.empty()){
            int start = st2.top().first, end = st2.top().second;
            if (end > start){
                int i = start;
                for (; i<=end ;i++){
                    if (i<0 or i>=len)continue;
                    if (s[i] == '('){
                        st2.pop();
                        if (brackets[i]+1<=end)st2.push({brackets[i]+1,end});
                        if (brackets[i]-1>=i+1) st2.push({brackets[i]-1, i+1});
                        break;
                    }
                    else if (s[i] == ')'){st2.pop();break;}
                    else ans += s[i];
                }
                if (i>end)st2.pop();
            }
            else {
                int i=start;
                for (; i>=end ;i--){
                    if (i<0 or i>=len)continue;
                    if (s[i] == ')'){
                        st2.pop();
                        if (brackets[i]-1 >= end) st2.push({brackets[i]-1,end});
                        if (brackets[i]+1 <= i-1) st2.push({brackets[i]+1, i-1});
                        break;
                    }
                    else if (s[i] == '('){st2.pop();break;}
                    else ans += s[i];
                }
                if (i<end)st2.pop();
            }
        }
        return ans ;
    }
};