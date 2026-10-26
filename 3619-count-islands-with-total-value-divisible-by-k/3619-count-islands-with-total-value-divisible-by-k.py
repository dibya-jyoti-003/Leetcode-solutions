class Solution:
    def countIslands(self, grid: List[List[int]], k: int) -> int:
        m = len(grid)
        n = len(grid[0])
        res = 0
        dir = [0,-1,0,1,0]
        vis = [[0]*n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if vis[i][j] or grid[i][j] == 0:
                    continue
                q = deque()
                ans = 0
                q.append((i,j))
                vis[i][j] = 1
                while q:
                    row,col = q.popleft()
                    ans += grid[row][col]
                    for l in range(4):
                        p = dir[l]
                        v = dir[l+1]
                        if row+p>=0 and col+v>=0 and row+p<m and col+v<n and grid[row+p][col+v]>0 and vis[row+p][col+v]==0:
                            q.append((row+p, col+v))
                            vis[row+p][col+v]=1
                res += (ans % k == 0)
        return res