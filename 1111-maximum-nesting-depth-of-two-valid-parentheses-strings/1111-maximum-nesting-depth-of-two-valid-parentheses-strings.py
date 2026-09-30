class Solution:
    def maxDepthAfterSplit(self, seq: str) -> list[int]:
        depth = 0
        level = []
        for c in seq:
            if c == '(':
                depth = 1 - depth
                level.append(depth)
            else:
                level.append(depth)
                depth = 1 - depth        
        return level