import typing as List

def subsets(self, nums: List[int]) -> List[List[int]]:
    res = []
    def dfs(elem: List[int], index: int):
        res.append(elem[:])
            
        for i in range(index, len(nums)):
            dfs(elem + [nums[i]], i+1)
                    
    dfs([], 0)
    return res