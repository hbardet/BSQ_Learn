const std = @import("std");

pub fn open_file(file_path: []const u8) ![]u8 {
    var file = try std.fs.cwd().openFile(file_path, .{});
    defer file.close();

    const allocator = std.heap.page_allocator;
    var buffer = std.ArrayList(u8).init(allocator);
    defer buffer.deinit();

    var in_stream = file.reader();

    const read_size = 1024;
    var temp_buffer: [read_size]u8 = undefined;

    while (true) {
        const read_bytes = try in_stream.read(temp_buffer[0..]);
        if (read_bytes == 0) break;
        try buffer.appendSlice(temp_buffer[0..read_bytes]);
    }

    return buffer.toOwnedSlice();
}
