#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main() {
    int src_fd, dst_fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    /* Open the source file in read-only mode */
    src_fd = open("pavan.txt", O_RDONLY);
    if (src_fd == -1) {
        perror("open source file");
        return 1;
    }

    /* Open the destination file in write-only mode */
    dst_fd = open("kumar.txt", O_WRONLY | O_CREAT, 0644);
    if (dst_fd == -1) {
        perror("open destination file");
        return 1;
    }

    /* Copy the content from the source file to the destination file */
    while ((bytes_read = read(src_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(dst_fd, buffer, bytes_read);
        if (bytes_written!= bytes_read) {
            perror("write");
            return 1;
        }
    }

    /* Close the source and destination files */
    close(src_fd);
    close(dst_fd);

    printf("File copied successfully!\n");
    return 0;
}
