class Solution {
private:
    void forward(string s, auto& res, int li, int lj) {
        int bal = 0;
        for (int i = li; i < s.size(); i++) {
            bal += (s[i] == '(') - (s[i] == ')');
            if (bal >= 0) continue;
            for (int j = lj; j <= i; j++)
                if (s[j] == ')' and (j == lj or s[j - 1] != ')'))
                    forward(s.substr(0, j) + s.substr(j + 1), res, i, j);
            return;
        }
        backward(s, res, s.size() - 1, s.size() - 1);
    }

    void backward(string s, auto& res, int ri, int rj) {
        int bal = 0;
        for (int i = ri; i >= 0; i--) {
            bal += (s[i] == ')') - (s[i] == '(');
            if (bal >= 0) continue;
            for (int j = rj; j >= i; j--)
                if (s[j] == '(' and (j == rj or s[j + 1] != '('))
                    backward(s.substr(0, j) + s.substr(j + 1),res,i-1,j-1);
            return;
        }
        res.push_back(s);
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        forward(s, res, 0, 0);
        return res;
    }
};