class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        dp = [-1]*n
        def f(i):
            if i == n:
                return 1
            if dp[i] != -1:
                return dp[i]
            ans = 0
            if s[i] != '0':
                ans += f(i+1)
            if i+1 < n and 10<=int(s[i:i+2]) <= 26 :
                ans += f(i+2)
            dp[i] = ans
            return dp[i]
        return f(0)