#include <stdio.h>

// Use: opendir, readdir
#include <dirent.h>

// Use: 
#include <unistd.h>

int show_all = 0;

int main(int argc, char *argv[]) {
    int opt;

    // Parse command-line options using getopt. 
    // The only option we support is '-a'
    while ((opt = getopt(argc, argv, "a")) != -1) {
        switch (opt) {
            case 'a':
                show_all = 1;
                break;
            default:
                // If an unknown option is provided, 
                // print usage information and exit 
                // with an error code
                fprintf(stderr, "Usage: %s [-a] [path]\n", argv[0]);
                return 1;
        }
    }

    // Determine the path to list. If a path is provided as a
    // command-line argument, use it; otherwise, default to 
    // the current directory
    const char *path = (optind < argc) ? argv[optind] : "."; 

    // Open the directory specified by the path
    DIR *dir = opendir(path);
    if (!dir) {
        // If opendir fails, print an error message 
        // and return a non-zero exit code
        perror("opendir");
        return 1;
    }

    // Read the first entry in the directory and print its name
    struct dirent *entry;

    // Loop through the directory entries until there 
    // are no more entries to read
    while ((entry = readdir(dir)) != NULL) {
        // If the '-a' option is not set and the entry's name
        // starts with '.', skip it 
        // (this means it's a hidden file or directory)
        if(!show_all && entry->d_name[0] == '.') {
            // Skip hidden files and directories 
            // (those starting with '.')
            continue;
        }

        // Print the name of the current directory entry
        printf("%s\n", entry->d_name);
    }

    // After reading all entries, close the directory stream
    closedir(dir);

    return 0;
}