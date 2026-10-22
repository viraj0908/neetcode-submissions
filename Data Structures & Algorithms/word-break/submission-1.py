class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        dp = [-1]*n
        def f(i):
            if i == n:
                return 1
            if dp[i] != -1:
                return dp[i]
            ans = 0
            for j in range(i,n):
                if s[i:j+1] in wordDict:
                    ans = (ans or f(j+1))
                if ans :
                    break
            dp[i] = ans
            return dp[i]
        return True if f(0) else False