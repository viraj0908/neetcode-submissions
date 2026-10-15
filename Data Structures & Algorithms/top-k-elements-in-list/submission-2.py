class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mp = defaultdict(int)
        freq = [[] for i in range(len(nums) + 1)]
        for num in nums:
            mp[num] += 1
        ans = []
        for i,f in mp.items():
            freq[f].append(i)
        for i in range(len(nums) , 0 , -1):
            for n in freq[i]:
                ans.append(n)
                if len(ans) == k:
                    return ans
        