class Solution {
public:
    string reverseParentheses(string s) {
        int len = s.size();
        unordered_map<int, int> bracket;
        stack<int> st;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(') st.push(i);
            else if (s[i] == ')') {
                int open = st.top();
                st.pop();
                bracket[open] = i;
                bracket[i] = open;
            }
        }
        string ans;
        int i = 0, dir = 1;
        while (i >= 0 && i < len) {
            if (s[i] == '(' || s[i] == ')') {
                i = bracket[i];
                dir = -dir;
            } 
            else ans += s[i];
            i += dir;
        }
        return ans;
    }
};