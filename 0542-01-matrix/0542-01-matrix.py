class Solution:
    def updateMatrix(self, mat: list[list[int]]) -> list[list[int]]:
        m = len(mat)
        n = len(mat[0])
        INF = m + n + 1
        grid = [[0 if mat[i][j] == 0 else INF for j in range(n)] for i in range(m)]
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 1:
                    if i>0 :
                        grid[i][j] = min(grid[i][j],1 + grid[i-1][j])
                    if j>0 :
                        grid[i][j] = min(grid[i][j], 1 + grid[i][j-1])
        for i in range(m-1,-1,-1):
            for j in range(n-1,-1,-1):
                if mat[i][j] == 1:
                    if i<m-1 :
                        grid[i][j] = min(grid[i][j],1 + grid[i+1][j])
                    if j<n-1 :
                        grid[i][j] = min(grid[i][j], 1 + grid[i][j+1])
        return grid
        