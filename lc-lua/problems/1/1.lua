function twoSum(nums, target)
    local m = {}
    for i, n in pairs(nums) do
        local v = m[n]
        if v then
            return {v, i}
        end
        m[target - n] = i
    end
    return nil
end

-- I really like that everything is a table in this language
-- but, ~= and 1 index are weird decisions

local test_1_result = twoSum({2, 7, 11, 15}, 9)
if (test_1_result[1] ~= 1 or test_1_result[2] ~= 2) then
    print("test 1 failed")
else 
    print("test 1 passed")
end

local test_2_result = twoSum({3, 2, 4}, 6)
if (test_2_result[1] ~= 2 or test_2_result[2] ~= 3) then
    print("test 2 failed")
else 
    print("test 2 passed")
end

local test_3_result = twoSum({3, 3}, 6)
if (test_3_result[1] ~= 1 or test_3_result[2] ~= 2) then
    print("test 3 failed")
else 
    print("test 3 passed")
end