/*
This program demonstrates that glibc transparently provides errno support
*/

#include <stdio.h>
#include <errno.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#include <string.h>

int main(void) {
    
    int fd;

    /*****************************
     *  O_EXCL
        When given with O_CREAT, this flag will cause the call to open() to fail if the file
        given by name already exists. This is used to prevent race conditions on file creation.
        If O_CREAT is not also provided, this flag has no meaning.

     *  O_CREAT

        If the file denoted by name does not exist, the kernel will create it. If the file already
        exists, this flag has no effect unless O_EXCL is also given.
     ****************************/
    
    fd = open("./error_file.txt", O_CREAT | O_EXCL );

    if(fd == -1) perror (strerror(errno));

    return(0);

}