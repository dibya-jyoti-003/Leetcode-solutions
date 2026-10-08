class Solution:
    
    def solve (self,n,k,temp,p):
        if k == 0:
            self.ans.append(temp.copy())
            return 
        for i in range(p+1,n+1):
            temp.append(i)
            self.solve(n,k-1,temp,i)
            temp.pop()

    def combine(self, n: int, k: int) -> list[list[int]]:
        self.ans = []
        self.solve(n,k,[],0)
        return self.ans 