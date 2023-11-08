from typing import List

def twoSum(nums: List[int], target: int) -> List[int]:
    m = {}
    for i, n in enumerate(nums):
        v = m.get(n)
        if v is not None:
            return [v, i]
        m[target-n] = i
    return []