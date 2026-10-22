class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        res = max(nums)
        currMax ,currMin = 1,1
        for i in nums:
            if i == 0:
                currMax = 1
                currMin = 1
                continue
            tmp = currMax
            currMax = max(i*currMax,i*currMin,i)
            currMin = min(i*tmp,i*currMin,i)
            res = max(res,currMax)
        return res