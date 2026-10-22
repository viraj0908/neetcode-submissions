class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        dp = [[-1] * 2 for _ in range(n)]
        def f(i,buy):
            if i >= n:
                return 0
            if dp[i][buy] != -1:
                return dp[i][buy]
            ans = -1e9
            if buy == 0:
                ans = max(ans , f(i + 1,buy))
                ans = max(ans , -prices[i] + f(i+1,1))
            else :
                ans = max(ans , f(i+1,buy))
                ans = max(ans , prices[i] + f(i+2,0))
            dp[i][buy] = ans
            return dp[i][buy]
        return f(0,0)
