class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        mp = defaultdict(int)
        for i in range(len(nums)):
            mp[nums[i]] += 1
        ans = 0
        for i in range(len(nums)):
            if nums[i] - 1 in mp:
                continue
            else :
                cur = 1
                x = nums[i] + 1
                while x in mp :
                    cur += 1;
                    x += 1
                ans = max(ans , cur)
        return ans