#include <stdio.h>

// Use: opendir
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

    return 0;
}