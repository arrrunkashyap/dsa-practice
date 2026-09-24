class Solution:

    def pow(self, x,n):
        if n==0:
            return 1
        a = self.pow(x ,n//2)
        if n%2 ==0:
            return a*a
        else :
            return a*a*x
    def myPow(self, x: float, n: int) -> float:
        if n<=0:
            return 1/ self.pow(x, n*(-1))
        else :
            return self.pow(x,n)