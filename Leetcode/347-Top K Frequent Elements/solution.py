import collections
import heapq
from typing import List

def topKFrequent(self, nums: List[int], k: int) -> List[int]:
    freqs = collections.Counter(nums)
    freqs_heap = []
    for f in freqs:
        heapq.heappush(freqs_heap, (-freqs[f], f))
            
    res = list()
    for _ in range(k):
        res.append(heapq.heappop(freqs_heap)[1])
    return res

def topKFrequent(self, nums: List[int], k: int) -> List[int]:
    return list(zip(*collections.Counter(nums).most_common(k)))[0]