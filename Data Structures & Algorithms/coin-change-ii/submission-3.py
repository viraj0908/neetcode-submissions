class Solution:
    def change(self, amount: int, nums: List[int]) -> int:
        n = len(nums)
        dp = [[-1]*(amount+1) for _ in range(n)]
        def f(i,j):
            if j == 0:
                return 1
            if i == n:
                return 0
            if dp[i][j] != -1:
                return dp[i][j]
            ans = f(i+1,j)
            if j - nums[i] >= 0:
                ans += f(i,j-nums[i])
            dp[i][j] = ans
            return dp[i][j]
        return f(0,amount)
        