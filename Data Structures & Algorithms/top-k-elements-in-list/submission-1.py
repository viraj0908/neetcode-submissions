class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = defaultdict(int)
        for num in nums:
            freq[num]+=1
        v = []
        for i,f in freq.items():
            v.append([f,i])
        v.sort()
        ans = []
        while len(ans) < k :
            ans.append(v.pop()[1])
        return ans
