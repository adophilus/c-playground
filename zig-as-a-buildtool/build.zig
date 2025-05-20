const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const exe = b.addExecutable(.{ .name = "zig-as-a-buildtool", .target = target, .optimize = optimize });

    const files = [_][]const u8{"src/main.c"};

    const flags = [_][]const u8{ "-Wall", "-Wextra", "-pedantic", "-std=c2x" };

    exe.addCSourceFiles(.{
        .files = &files,
        .flags = &flags,
    });

    exe.linkLibC();
    b.installArtifact(exe);
}
