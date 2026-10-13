class Solution:
    def highestPeak(self, isWater: list[list[int]]) -> list[list[int]]:
        m = len(isWater)
        n = len(isWater[0])
        q = deque()
        vis = {}
        dx = [-1,0,1,0]
        dy = [0,-1,0,1]
        INF = m+n+1
        ans = [[INF] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if isWater[i][j] == 1:
                    q.append((i,j,0))
                    vis[(i,j)] = True
        while q:
            row, col, dist = q.popleft()
            ans[row][col] = min(ans[row][col], dist)
            for i in range(4):
                new_x = row + dx[i]
                new_y = col + dy[i]
                if 0 <= new_x < m and 0 <= new_y < n and (new_x,new_y) not in vis:
                    vis[(new_x,new_y)] = True 
                    q.append((new_x,new_y,dist+1))
        return ans 
        
            