class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ans,curr = -1e9,0
        for i in nums:
            curr = max(curr + i , i)
            ans = max(ans , curr)
        return ans