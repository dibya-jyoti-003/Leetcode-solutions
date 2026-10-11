import random

class Solution:
    def __init__(self, m: int, n: int):
        self.m = m
        self.n = n
        self.total = m * n
        self.remaining = self.total
        self.mp = {}

    def flip(self) -> list[int]:
        x = random.randrange(self.remaining)
        chosen = self.mp.get(x, x)
        last = self.remaining - 1
        self.mp[x] = self.mp.get(last, last)
        self.remaining -= 1
        return [chosen // self.n, chosen % self.n]

    def reset(self) -> None:
        self.remaining = self.total
        self.mp.clear()