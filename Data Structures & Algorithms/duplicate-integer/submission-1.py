class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        mp = {}
        for i in nums:
            if i in mp : 
                return True
            mp[i] = 1
        return False