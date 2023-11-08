const std = @import("std");

fn twoSum(nums: []i32, target: i32) ![]i32 {
    var gpa = std.heap.GeneralPurposeAllocator(.{}){};
    const allocator = gpa.allocator();
    var m = std.AutoHashMap(i32, i32).init(allocator);
    for (0.., nums) |_i, n| {
        const i: i32 = @intCast(_i);
        if (m.get(n)) |v| {
            var out = [_]i32{ v, i };
            var out_copy = allocator.dupe(i32, &out);
            return out_copy;
        }
        try m.put(target - n, i);
    }
    return &.{};
}

test "twoSum_1" {
    var nums = [_]i32{ 2, 7, 11, 15 };
    const target: i32 = 9;
    var want = [_]i32{ 0, 1 };
    var result = try twoSum(&nums, target);
    try std.testing.expect(std.mem.eql(i32, &want, result));
}

test "twoSum_2" {
    var nums = [_]i32{ 3, 2, 4 };
    const target: i32 = 6;
    var want = [_]i32{ 1, 2 };
    var result = try twoSum(&nums, target);
    try std.testing.expect(std.mem.eql(i32, &want, result));
}

test "twoSum_3" {
    var nums = [_]i32{ 3, 3 };
    const target: i32 = 6;
    var want = [_]i32{ 0, 1 };
    var result = try twoSum(&nums, target);
    try std.testing.expect(std.mem.eql(i32, &want, result));
}
