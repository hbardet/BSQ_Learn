const std = @import("std");
const print = std.debug.print;
const open_file = @import("open_file.zig");

const Error = error{
    BadNbrArgument,
    BadFile,
};

pub fn main() !void {
    // Get the command-line arguments
    const args = std.process.argsAlloc(std.heap.page_allocator) catch |err| {
        std.debug.print("Failed to allocate arguments: {}\n", .{err});
        return err;
    };
    defer std.process.argsFree(std.heap.page_allocator, args);

    // Verify that there is at least one argument (the program name itself)
    if (args.len < 2) {
        std.debug.print("Usage: {s} <file_path>\n", .{args[0]});
        return Error.BadNbrArgument;
    }

    // Get the file path from the arguments
    const file_path = args[1];

    // Open the file and retrieve its content
    const fileContents = try open_file.open_file(file_path);

    // Display the content of the file
    print("File content:\n{s}\n", .{fileContents});
}
