import pytest
import p1

def test_twoSum():
    assert p1.twoSum([2, 7, 11, 15], 9) == [0, 1]
    assert p1.twoSum([3, 2, 4], 6) == [1, 2]
    assert p1.twoSum([3, 3], 6) == [0, 1]