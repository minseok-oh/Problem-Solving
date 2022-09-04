from typing import List

def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        return sum([nums[i] for i in range(len(nums)) if i % 2 == 0])

def arrayPairSum(self, nums: List[int]) -> int:
        return sum(sorted(nums)[::2])