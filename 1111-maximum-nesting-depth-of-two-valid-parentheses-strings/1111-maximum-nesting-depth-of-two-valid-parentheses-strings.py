class Solution:
    def maxDepthAfterSplit(self, seq: str) -> list[int]:
        st = deque()
        ans = []
        pos = 0
        for ch in seq:
            if ch == '(':
                if st:
                    pos = 1-st[-1]
                else :
                    pos = 0
                st.append(pos)
                ans.append(pos)
            else :
                top = st[-1]
                st.pop()
                ans.append(top)
        return ans 

            