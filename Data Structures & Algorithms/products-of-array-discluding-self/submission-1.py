class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        p , zero ,prod= 1,0,[]
        for i in range(len(nums)):
            if nums[i] == 0 :
                prod.append(p)
                p = 1
                zero+=1
            else:
                p *= nums[i]
        prod.append(p)
        ans = []
        if zero == 0:
            for i in range(len(nums)):
                ans.append(p // nums[i])
        elif zero == 1:
            for i in range(len(nums)):
                if nums[i] == 0:
                    ans.append(prod[0]*prod[1])
                else :
                    ans.append(0)
        else:
            ans = [0]*len(nums)
        return ans
        