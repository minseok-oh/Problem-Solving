import itertools
import typing as List

def combine(self, n: int, k: int) -> List[List[int]]:
    res = []
    def dfs(elem: List[int], start: int, k: int):
        if k == 0:
            res.append(elem[:])
            return
            
        for i in range(start, n+1):
            elem.append(i)
            dfs(elem, i+1, k-1)
            elem.pop()
                
    dfs([], 1, k)
    return res

def combine(self, n: int, k: int) -> List[List[int]]:
        return list(itertools.combinations(range(1, n+1), k))