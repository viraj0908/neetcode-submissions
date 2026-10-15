class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numSet = set(nums)
        ans = 0
        for num in numSet:
            if num - 1 not in numSet:
                cur = 1
                x = num + 1
                while x in numSet:
                    x += 1
                    cur += 1
                ans = max(ans , cur)
        return ans