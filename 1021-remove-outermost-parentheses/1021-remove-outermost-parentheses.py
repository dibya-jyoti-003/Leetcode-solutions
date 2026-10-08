class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        stack = []
        ans = ""
        for ch in s:
            if ch == '(':
                if stack:
                    ans += ch
                stack.append('(')
            else :
                stack.pop()
                if stack:
                    ans += ch
        return ans 