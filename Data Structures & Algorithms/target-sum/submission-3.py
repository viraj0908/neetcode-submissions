class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        n = len(nums)
        maxSum = 0
        for i in nums:
            maxSum += i
        dp = [[-1] * (2*maxSum + 1) for _ in range(n)]
        def f(i,j):
            if i == n:
                if j == target + maxSum:
                    return 1
                else :
                    return 0
            if dp[i][j] != -1:
                return dp[i][j]
            ans = 0
            ans += f(i+1,j+nums[i])
            ans += f(i+1,j-nums[i])
            dp[i][j] = ans
            return dp[i][j]
        return f(0,maxSum)