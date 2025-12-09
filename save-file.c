
// student database system 

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#include "common.h"


// this function is to delete the existing file and save the entered new student details to create a new file...

void write_file(student *data, int num, const char *file){
    int fd;
    int total_bytes = 0;
    int bytes_written = 0;

    fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0777);
    if (fd == -1){
	printf("File open error: %i (%s)\n", errno, strerror(errno));
	return;
    }

    for (int i = 0; i < num; i++){
	bytes_written = write(fd, data + i, sizeof(student));
	if (bytes_written == -1){
	    printf("File write error: %i (%s)\n", errno, strerror(errno));
	    close(fd);
	    return;
	}
	total_bytes += bytes_written;
    }

    close(fd);
    printf("Successfully wrote %d students to %s (%i bytes)\n", num, file, total_bytes);
}

