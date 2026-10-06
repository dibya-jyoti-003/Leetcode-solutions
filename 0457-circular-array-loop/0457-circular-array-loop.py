class Solution:
    def circularArrayLoop(self, nums: list[int]) -> bool:
        n = len(nums)
        vis = [False] * n
        for i in range(n):
            if vis[i]:
                continue
            curr = i
            direction = nums[i] > 0
            path = set()
            while True:
                if vis[curr]:
                    break
                if (nums[curr] > 0) != direction:
                    break
                if curr in path:
                    return True
                path.add(curr)
                nxt = (curr + nums[curr]) % n
                if nxt == curr:
                    break
                curr = nxt
            for node in path:
                vis[node] = True

        return False