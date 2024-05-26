const std = @import("std");

pub fn open_file() ![]u8 {
    var file = try std.fs.cwd().openFile("../../bsq_map/map_default/map_100_100", .{});
    defer file.close();
    var buf_reader = std.io.bufferedReader(file.reader());
    var in_stream = buf_reader.reader();

    const buf: []u8 = undefined;
    while (try in_stream.readUntilDelimiterOrEof(buf, '\n')) |line| {
        std.debug.print("{s}", line);
    }
    return buf;
}
