class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n = len(coins)
        dp = [-1]*(amount+1)
        def f(sum):
            if sum == 0:
                return 0
            if dp[sum] != -1:
                return dp[sum]
            ans = 1e9
            for i in range(n):
                if sum - coins[i] >=0 :
                    ans = min(ans , 1 + f(sum - coins[i]))
            dp[sum] = ans
            return dp[sum]
        if f(amount) == 1e9 :
            return -1
        else :
            return f(amount)
