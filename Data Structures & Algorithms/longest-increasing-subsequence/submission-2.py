
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        tail = []

        def lower_bound(tail, x):
            l, r = 0, len(tail)

            while l < r:
                mid = l + (r - l) // 2

                if tail[mid] >= x:
                    r = mid
                else:
                    l = mid + 1

            return l

        for x in nums:
            ind = lower_bound(tail, x)

            if ind < len(tail):
                tail[ind] = x
            else:
                tail.append(x)

        return len(tail)
