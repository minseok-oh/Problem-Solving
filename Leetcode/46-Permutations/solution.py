import itertools
from typing import List

def permute(self, nums: List[int]) -> List[List[int]]:
    res = []
    prev_elem = []
        
    def dfs(elem: List[int]):
        if len(elem) == 0:
            res.append(prev_elem[:])
            return
            
        for e in elem:
            next_elem = elem[:]
            next_elem.remove(e)
                
            prev_elem.append(e)
            dfs(next_elem)
            prev_elem.pop()
                
    dfs(nums)
    return res

def permute(self, nums: List[int]) -> List[List[int]]:
        return list(itertools.permutations(nums))