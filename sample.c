#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define BUFSIZE 256

// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) {
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    const char* file_path = argv[1];
    struct stat file_stat;

    // Check if the file exists and get its size using fstat
    if (stat(file_path, &file_stat) != 0) {
        perror("Error getting file status");
        return -1;
    }

    // Print the size of the file in bytes
    printf("Size of file '%s': %ld bytes\n", file_path, file_stat.st_size);

    return 0;
}
