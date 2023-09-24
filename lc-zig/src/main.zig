const std = @import("std");

comptime {
    _ = @import("./problems/1/1.zig");
}

pub fn main() !void {
    const stdout = std.io.getStdOut().writer();
    try stdout.print("Hello, {s}!\n", .{"world"});
}
