from typing import List

def productExceptSelf(self, nums: List[int]) -> List[int]:
    out = []
    p = 1
    for i, val in enumerate(nums):
        out.append(p)
        p = p * val
        
    p = 1
    for i in range(len(nums)-1, 0 - 1, -1):
        out[i] = out[i] * p
        p = p * nums[i]
    return out