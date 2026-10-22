class Solution:
    def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
        if len(hand) % groupSize != 0:
            return False
        count= {}
        for i in hand:
            count[i] = 1 + count.get(i,0)
        heap = []
        for i in count.keys():
            heapq.heappush(heap,i)
        while heap:
            n = heap[0]
            for k in range(n,n + groupSize):
                if k not in count:
                    return False
                count[k]-=1
                if count[k] == 0:
                    if k != heap[0]:
                        return False
                    else :
                        heapq.heappop(heap)
        return True