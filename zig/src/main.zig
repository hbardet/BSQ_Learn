const std = @import("std");
const print = std.debug.print;
const open_file = @import("open_file.zig");

const Error = error{
    BadNbrArgument,
    BadFile,
};

pub fn main() !void {

    // Récupérer les arguments de la ligne de commande

    // Vérifier qu'il y a au moins un argument (le nom du programme)
    // Chemin du fichier à ouvrir

    // Ouvrir le fichier et récupérer son contenu
    const fileContents = try open_file.open_file();

    // Afficher le contenu du fichier
    print("Contenu du fichier '':\n{}\n", .{fileContents});
}
