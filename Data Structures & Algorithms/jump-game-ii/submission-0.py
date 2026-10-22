class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [-1]*n
        def f(i):
            if i >= n-1:
                return 0
            if dp[i] != -1:
                return dp[i]
            if nums[i] == 0:
                return 1e9
            ans = 1e9
            for j in range(1,nums[i]+1):
                if f(i + j) != 1e9:
                    ans = min(ans , 1 + f(i+j))
            dp[i] = ans
            return dp[i]
        return f(0)