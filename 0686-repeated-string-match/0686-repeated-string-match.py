class Solution:
    def repeatedStringMatch(self, a: str, b: str) -> int:
        min_repeat = (len(a) + len(b) -1) // len(a)
        if b in a*min_repeat:
            return min_repeat
        if b in a * (min_repeat + 1):
            return min_repeat + 1
        return -1