import typing as List

def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
    res = []
    def dfs(csum: int, elem: List[int], index: int):
        if csum < 0:
            return
        if csum == 0:
            res.append(elem[:])
            return
            
        for i in range(index, len(candidates)):
            elem.append(candidates[i])
            dfs(csum - candidates[i], elem, i)
            elem.pop()
                
    dfs(target, [], 0)
    return res