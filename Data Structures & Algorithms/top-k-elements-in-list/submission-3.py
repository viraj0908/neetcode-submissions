class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mp = defaultdict(int)
        for num in nums:
            mp[num] += 1
        heap = []
        for n,f in mp.items():
            heapq.heappush(heap,(-f,n))
        ans = []
        while len(ans) < k:
            ans.append(heapq.heappop(heap)[1])
        return ans
        