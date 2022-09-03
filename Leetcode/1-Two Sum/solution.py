from typing import List

def twoSum(self, nums: List[int], target: int) -> List[int]:
    for i in range(len(nums)):
        for j in range(i+1, len(nums)):
            if nums[i] + nums[j] == target:
                return [i, j]

def twoSum(self, nums: List[int], target: int) -> List[int]:
    nums_map = {}
        
    for i, val in enumerate(nums):
        nums_map[val] = i
            
    for i, val in enumerate(nums):
        if target-val in nums_map and i != nums_map[target-val]:
            return [i, nums_map[target-val]]