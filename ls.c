#include <stdio.h>

// Use: opendir, readdir
#include <dirent.h>

int main(int argc, char *argv[]) {
    const char *path = (argc > 1) ? argv[1] : ".";

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
    // Reference: man 3 readdir
    entry = readdir(dir);
    printf("%s\n", entry->d_name);

    return 0;
}